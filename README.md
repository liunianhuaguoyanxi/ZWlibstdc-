# ZWlibstdc-
## XCODE10移除了libstdc++，需要增加缺失的文件适配老程序（XCODE 10 REMOVED libstdc++ , NEED TO ADD SOME FILES TO SUPPORT）

## 网上有很多兼容Xcode10移除了libstdc++后程序无法运行的方案，但感觉都不全面，因为本身项目中用了很多c++的编码，这边亲身研究了下，发现要添加和合并以下的文件，老程序才能完美在xcode10上运行，而且不影响审核。
## 目前已经用xcode10迭代了很多个app版本，真机和模拟器都完美运行。

### 将文件1内容添加到该路径中： (add the file 1 content into such path：)
#### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/

### 将文件2内容添加到该路径中： (add the file 2 content into such path：)
#### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/lib/

### 将文件3内容添加到该路径中： (add the file 3 content into such path：)
#### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/lib/

### 将命名为include的文件合并替换为文件4内容： (merge such the file which named “include” with  the file 4 content：)
#### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/include

### 将命名为include的文件合并替换为文件5内容： ： (merge such the file which named “include” with  the file 5 content：)
#### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/include
