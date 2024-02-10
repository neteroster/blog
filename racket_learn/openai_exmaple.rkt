;; This is an example Racket program for asynchronously sending requests to the OpenAI API and saving the results.
;; Author: NeterOster (neteroster@gmail.com)
;; License: MIT
;; 2024-02-10

#lang racket/base

(require racket/port)
(require racket/vector)
(require net/http-client)
(require json)

(define (port->string/utf-8 port)
  (bytes->string/utf-8 (port->bytes port)))

(define openai-base "api.aigcbest.top")
(define openai-uri "/v1/chat/completions")
(define api-key "HIDDEN")

(define (send-openai-request message id result-thread)
  (define data 
    (jsexpr->bytes
      `#hasheq((model . "gpt-3.5-turbo")
              (messages . 
                (#hasheq((role . "user")
                         (content . ,message)))))))
  (define-values (status response body)
    (http-sendrecv openai-base openai-uri
                   #:data data
                   #:method "POST"
                   #:ssl? 'tls13
                   #:headers `("Content-Type: application/json"
                               ,(format "Authorization: Bearer ~a" api-key))))
  
  (define js-result (string->jsexpr (port->string/utf-8 body)))
  (define choice (car (hash-ref js-result 'choices)))
  (define msg (hash-ref choice 'message))
  (define content (hash-ref msg 'content))
  
  (thread-send result-thread `(,id . ,content)))


(define (send-multiple-requests n)
  
  (define ct (current-thread))
  
  (define requests 
    (for/list ([i (in-range n)])
      (thread (lambda () (send-openai-request (format "~a + ~a = ?" i (+ i 1)) i ct)))))

  (define res (make-vector n))
  
  (for ([i (in-range n)])
    (vector-set! res i (thread-receive)))

  (vector-sort! res < #:key car)
  (vector-map! cdr res)

  res)

(send-multiple-requests 50)

