# 光栅化中的变换操作

## 模型变换

指对模型本身进行的变换.

### 旋转变换（2D）

绕原点的逆时针旋转变换：
$$
\mathbf{R}_\theta=\begin{bmatrix}
\cos \theta & -\sin \theta & 0\\
\sin\theta & \cos \theta & 0\\
0 & 0 & 1
\end{bmatrix}
$$

### 平移变换（2D）

$$
\mathbf{T}(t_x, t_y) =
\begin{bmatrix}
1 & 0 & t_x\\
0 & 1 & t_y\\
0 & 0 & 1
\end{bmatrix}
$$

3D 的平移变换类似

### 旋转变换（3D）

分为绕 $x, y, z$ 轴的旋转
$$
\mathbf{R}_x(\alpha) = 
\begin{pmatrix}
1 & 0 & 0 & 0\\
0 & \cos \alpha & -\sin\alpha & 0 \\
0 & \sin \alpha & \cos\alpha & 0\\
0 & 0 & 0 &1
\end{pmatrix}
$$

$$
\mathbf{R}_y(\alpha) = 
\begin{pmatrix}
\cos\alpha & 0 & \sin\alpha & 0\\
0 & 1 & 0 & 0 \\
-\sin\alpha&0 & \cos\alpha & 0\\
0 & 0 & 0 &1
\end{pmatrix}
$$

$$
\mathbf{R}_z(\alpha) = 
\begin{pmatrix}
\cos\alpha & -\sin\alpha & 0 & 0\\
\sin\alpha & \cos \alpha & 0 & 0 \\
0 & 0 & 1 & 0\\
0 & 0 & 0 &1
\end{pmatrix}
$$

绕任意一个轴（单位方向向量为 $\mathbf{n}$）旋转
$$
\mathbf{R}(\mathbf{n},\alpha) = \cos(\alpha)\mathbf{I} + (1-\cos\alpha)\mathbf{nn}^T + \sin\alpha
\begin{pmatrix}
0 & -n_z & n_y \\
n_z & 0 & -n_x \\
-n_y & n_x & 0
\end{pmatrix}
$$
右边矩阵本质上是叉乘，整个公式推导参考 [这里](https://sites.cs.ucsb.edu/~lingqi/teaching/resources/GAMES101_Lecture_04_supp.pdf).（核心思想：把任意向量分解为旋转轴方向和垂直旋转轴方向的向量，只有垂直旋转轴方向的向量旋转）.

## 视图变换

指通过相对运动不变性把相机转化到原点、对着 $z$ 轴负向，上方向为 $y$ 轴的情形.

相机的参数：$\mathbf{e}$ 位置，$\mathbf{\hat{g}}$ 看的方向，$\mathbf{\hat{t}}$ 上方向. 注意 $\mathbf{\hat{g}}$ 会与 $\mathbf{\hat{t}}$ 垂直.

视图变换（View / Camera Transformation）：先平移再旋转
$$
M_{\text{view}} = R_{\text{view}}T_{\text{view}}
$$
其中
$$
T_{\text{view}} = \begin{bmatrix}
1 & 0 & 0 & -x_e \\
0 & 1 & 0 & -y_e \\
0 & 0 & 1 & -z_e \\
0 &0 & 0 & 1
\end{bmatrix}
$$

$$
R_{\text{view}}=
\begin{bmatrix}
x_{\hat{g} \times \hat{t}} & y_{\hat{g} \times \hat{t}} & z_{\hat{g} \times \hat{t}} & 0\\
x_t & y_t & z_t & 0\\
x_{-g} & y_{-g} & z_{-g} & 0\\
0 & 0 &0 & 1
\end{bmatrix}
$$

How?（Tips: $R_{\text{view}}^{-1}$，课件.）

## 投影变换

### 正交投影（Orthographic Projection）

把一个任意位置的立方体变到以原点为中心，然后缩放成正方体 $[-1, 1]^2$
$$
M_{\text{ortho}}=
\begin{bmatrix}
\frac{2}{r-l} & 0 & 0 & 0 \\
0 & \frac{2}{t-b} & 0 & 0 \\
0 & 0 & \frac{2}{n-f} & 0\\
0 & 0 & 0 &1
\end{bmatrix}
\begin{bmatrix}
1 & 0 & 0 & -\frac{r+l}{2} \\
0 & 1 & 0 & -\frac{t+b}{2} \\
0 & 0 & 1 & -\frac{n+f}{2}\\
0 & 0 & 0 &1
\end{bmatrix}
$$

### 透视投影（Perspective Projection）

先把视锥变换为长方体，然后进行正交投影.
$$
M_{\text{persp}} = M_{\text{ortho}}M_{\text{p2o}}
$$

$$
M_{\text{p2o}}=
\begin{pmatrix}
 n & 0 & 0 & 0\\
 0 & n & 0 & 0\\
 0 & 0 & n+f & -nf \\
 0 & 0 & 1 & 0
\end{pmatrix}
$$

其中 $n$ 是近平面 $z$ 坐标，$f$ 为远平面 $ z $ 坐标.

How？（课件）