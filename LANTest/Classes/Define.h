//
//  Define.h
//  云售后
//
//  Created by 天智 on 16/5/27.
//  Copyright © 2016年 天智. All rights reserved.
//

#ifndef Define_h
#define Define_h
#define s 44
//-------------------获取设备大小-------------------------
//NavBar高度
#define NavigationBar_HEIGHT        44
#define StatusBar_HEIGHT            (IsIphoneX ? 44 : 20)
#define StatusBar_NaviBar_HEIGHT    (NavigationBar_HEIGHT + StatusBar_HEIGHT)
#define IPhoneXBottom_HEIGHT        (IsIphoneX ? 34 : 0)

//获取屏幕 宽度、高度
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

//-------------------获取设备大小-------------------------


//-------------------打印日志-------------------------
//DEBUG  模式下打印日志,当前行
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif


//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif

//DEBUG  模式下打印日志,当前行 并弹出一个警告
#ifdef DEBUG
#   define ULog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }
#else
#   define ULog(...)
#endif

#define ALERT(msg)  UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" message:msg  delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil]; [alert show];

//---------------------打印日志--------------------------


//----------------------系统----------------------------


//获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion ［UIDevice currentDevice] systemVersion]

#define IsIphone4       [[UIScreen mainScreen] bounds].size.height == 480 //320*480
#define IsIphone5       [[UIScreen mainScreen] bounds].size.height == 568 //320*568
#define IsIphone6       [[UIScreen mainScreen] bounds].size.height == 667 //375*667
#define IsIphone6Plus   [[UIScreen mainScreen] bounds].size.height == 736 //414*736
#define IsIphoneX       [[UIScreen mainScreen] bounds].size.height == 812 //375*812

#define APP_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]  //
#define APP_BUILD_VERSION [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]  //

//定义一个define函数
#define TT_RELEASE_CF_SAFELY(__REF) { if (nil != (__REF)) { CFRelease(__REF); __REF = nil; } }

//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//获取NSDocumentDirectory路径
#define DocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
#define CachePath    [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask,YES) firstObject]

//----------------------系统----------------------------






//----------------------颜色类---------------------------
// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


// 获取RGB颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)

//背景色
#define BACKGROUND_COLOR UIColorFromRGB(0xe7e7e7)
#define LINECOLOR UIColorFromRGB(0xe4e4e4)
#define TABLEVIEWBACKGROUNDCOLOR UIColorFromRGB(0xe7e7e7)
#define NAVIGATIONBACKCOLOR UIColorFromRGB(0x00bcd4)
//清除背景色
#define CLEARCOLOR [UIColor clearColor]


//----------------------颜色类--------------------------



//----------------------其他----------------------------

//方正黑体简体字体定义
#define FONT(F) [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]



//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUserDefaults 实例化
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]

//弱引用self
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self

//缩放比例
#define Rate SCREEN_WIDTH / 375
#define PlusRate (SCREEN_WIDTH == 414 ? Rate : 1)


#define KEYWINDOW [UIApplication sharedApplication].keyWindow
//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)


#define iPhone5Size(size) SCREEN_WIDTH == 320 ? size * Rate : size

//----------------------用户----------------------------

#define DEFAULTIMAGE  @"defaultImage"
#define TOKEN_KEY @"access_token"
#define ACCESS_TOKEN  [USER_DEFAULT objectForKey:TOKEN_KEY]

#define DEFAULT_USER_PHONE_KEY @"user_phone"
#define DEFAULT_USER_PHONE  [USER_DEFAULT objectForKey:DEFAULT_USER_PHONE_KEY]


#endif /* Define_h */
