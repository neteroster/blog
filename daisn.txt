Data Archive Infomation System of NeterOster (DAISN)

VERSION: Draft.1
AUTHOR: NeterOster
DATE: 20210814

---

1. Introduction

This document describes a way of organizing NeterOster's personal data, making the data easy to access and well organized for further use and management. This document provides a naming system standard to tag and sort data in order to organize them properly. The information system is designed to be: easy to implement; capable for extending.

2. Type of Data

The target data are in many forms. All data should be or be encoded into files in a specific filesystem for archiving.

3. Structure of Files

3.1 File

A file is an basic object in a filesystem.

3.1.1 Attribute of Files

+ Description
=+ Main Description: A brief introduction to the file.
=+ Detail Description: A detailed introduction to the file.
+ Size: The size of the file.
+ File Name: The name of the file in a filesystem.

Refer to the `Readable Text Standard - Description for Files` for the standard of descriptions for different type of files.
Refer to the `Readable Text Standard - Name of Files` for the standard of naming the folder for different type of files.

3.2 File Group

The specific files enjoying some same attribute can form a file group. This relationship can be nested. File groups are folders in a specific filesystem. More accurately, the structure of a filesystem is imaged to the structure of file groups.

3.2.1 Attribute of File Groups

+ Description
=+ Main Description: A brief introduction to the file group.
=+ Detail Description: A detailed introduction to the file group.
+ Size: The total size of the file group, the sum of the size of all the content it contains.
+ Folder Name: The name of the corresponding folder of the file group.

Refer to the `Readable Text Standard - Description for Files Groups` for the standard of descriptions for different file groups.
Refer to the `Readable Text Standard - Folder Name for Files and File Groups` for the standard of naming the folder for different file groups.


