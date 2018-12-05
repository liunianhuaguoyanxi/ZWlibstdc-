# ZWlibstdc-
(XCODE10移除了libstdc++，需要增加缺失的文件适配老程序)XCODE 10 REMOVED libstdc++ , NEED TO ADD SOME FILES TO SUPPORT


add the file 1 content into such path：
### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/

add the file 2 content into such path：
### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/lib/

add the file 3 content into such path：
### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/lib/

replace such the file which named include with  the file 4 content：
### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/include

replace such the file which named include with  the file 5 content：
### /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/include
