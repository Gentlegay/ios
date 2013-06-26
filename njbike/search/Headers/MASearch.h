/*
 *  MTAsyncSearch.h
 *  iMapSDKLib
 *
 *  Created by yin cai on 11-8-30.
 *  Copyright 2011 AutoNavi. All rights reserved.
 *
 */

#import "MASearchOption.h"
#import "MASearchResult.h"

@protocol MASearchDelegate;

/*!
 @brief 异步查询类，从NSObject类继承。是一套异步查询的接口,基于Protocol Buffers实现。
 */
@interface MASearch : NSObject

/*!
 @brief 实现了MASearchDelegate协议的类指针
 */
@property(nonatomic,assign) id<MASearchDelegate> delegate;


/*!
 @brief 查询超时时间 默认超时时间20秒
 */
@property(nonatomic,assign) NSInteger timeOut;

/*!
 @brief MASearch类对象的初始化函数
 @param delegate 实现MASearchDelegate协议的对象id
 @return MASearch类对象id
 */
+(id)maSearchWithDelegate:(id<MASearchDelegate>)delegate NS_DEPRECATED_IOS(2_0, 6_0);

/*!
 @brief MASearch类对象的初始化函数
 @param key 搜索模块鉴权Key,(amap.com网站Code频道申请)
 @param delegate 实现MASearchDelegate协议的对象id
 @return MASearch类对象id
 */
-(id)initWithSearchKey:(NSString*)key Delegate:(id<MASearchDelegate>)delegate;


/*!
 @brief  POI 查询接口函数，即根据 POI 参数选项进行 POI 查询。
 @param searchOption POI 查询选项。具体属性字段请参考 MAPoiSearchOption 类。
 */
-(void)poiSearchWithOption:(MAPoiSearchOption*)searchOption;

/*!
 @brief 导航路径查询接口函数
 @param searchOption 导航路径查询选项(具体属性字段参考MASearchOption类中的定义)
 */
-(void)routeSearchWithOption:(MARouteSearchOption*)searchOption;

/*!
 @brief 公交导航查询接口函数
 @param searchOption 公交导航查询选项(具体属性字段参考MASearchOption类中的定义)
 */
-(void)busRouteSearchWithOption:(MABusRouteSearchOption*)searchOption;

/*!
 @brief 公交线路查询接口函数
 @param searchOption 公交线路查询选项(具体属性字段参考MASearchOption类中的定义)
 */
-(void)busLineSearchWithOption:(MABusLineSearchOption*)searchOption;

/*!
 @brief 两点之间距离查询函数
 @param searchOption 两点之间距离查询选项(具体属性字段参考MASearchOption类中的定义)
 */
-(void)distanceSearchWithOption:(MADistanceSearchOption*)searchOption;

/*!
 @brief GPS坐标偏移查询接口函数
 @param searchOption GPS坐标偏移查询查询选项(具体属性字段参考MASearchOption类中的定义)
 */
-(void)gpsOffsetSearchWithOption:(MARGCSearchOption*)searchOption;

/*!
 @brief 地理编码查询接口函数
 @param searchOption 地理编码查询选项(具体属性字段参考MTAsyncSearchOption类中的定义)
 */
-(void)geoCodingSearchWithOption:(MAGeoCodingSearchOption*)searchOption;

/*!
 @brief 逆地理编码查询接口函数
 @param searchOption 逆编码查询选项(具体属性字段参考MASearchOption类中的定义)
 */
-(void)reverseGeocodingSearchWithOption:(MAReverseGeocodingSearchOption*)searchOption;

@end

/*!
 @brief MASearchDelegate协议类，从NSObject类继承。
 */
@protocol MASearchDelegate<NSObject>

@optional

/*!
 @brief 搜索key
 @return 搜索key
 */
-(NSString *)keyForSearch NS_DEPRECATED_IOS(2_0, 6_0);

/*!
 @brief 通知查询成功或失败的回调函数
 @param searchOption 发起查询的查询选项
 @param errCode 错误码 \n
        000000  操作成功 \n
        000001  无查询结果 \n
        000002  调用服务发生异常 \n
        010001  非法坐标格式 \n
        010002  字符集编码错误 \n
        010003  Apikey为空 \n
        020000  产品未授权 \n
        020001  Apikey不正确 \n
        020002  Api账号不存在 \n
        020003  没有服务访问权限 \n
        040001  查询服务连接异常 \n
        040002  查询服务返回格式解析异常 \n
        050001  当前请求数据格式不支持 \n
 */
-(void)search:(id)searchOption Error:(NSString*)errCode;

/*!
 @brief POI查询回调函数
 @param poiSearchOption 发起POI查询的查询选项(具体字段参考MTAsyncSearchOption类中的定义)
 @param result 查询结果(具体字段参考MTAsyncSearchResult类中的定义)
 */
-(void)poiSearch:(MAPoiSearchOption*)poiSearchOption Result:(MAPoiSearchResult*)result;

/*!
 @brief 导航路径查询回调函数
 @param routeSearchOption 发起导航路径查询的查询选项(具体字段参考MASearchOption类中的定义)
 @param result 查询结果(具体字段参考MASearchResult类中的定义)
 */
-(void)routeSearch:(MARouteSearchOption*)routeSearchOption Result:(MARouteSearchResult*)result;

/*!
 @brief 公交导航查询回调函数
 @param busRouteSearchOption 发起公交导航查询的查询选项(具体字段参考MASearchOption类中的定义)
 @param result 查询结果(具体字段参考MAsyncSearchResult类中的定义)
 */
-(void)busRouteSearch:(MABusRouteSearchOption*)busRouteSearchOption Result:(MABusRouteSearchResult*)result;

/*!
 @brief 两点之间距离查询回调函数
 @param distanceSearchOption 发起公两点之间距离查询的查询选项(具体字段参考MASearchOption类中的定义)
 @param result 查询结果(具体字段参考MASearchResult类中的定义)
 */
-(void)distanceSearch:(MADistanceSearchOption*)distanceSearchOption Result:(MADistanceSearchResult*)result;

/*!
 @brief 公交线路查询回调函数
 @param busLineSearchOption 发起公交线路查询的查询选项(具体字段参考MASearchOption类中的定义)
 @param result 查询结果(具体字段参考MASearchResult类中的定义)
 */
-(void)busLineSearch:(MABusLineSearchOption*)busLineSearchOption Result:(MABusLineSearchResult*)result;

/*!
 @brief GPS坐标偏移查询回调函数
 @param gpsOffSearchOption 发起GPS坐标偏移查询的查询选项(具体字段参考MASearchOption类中的定义)
 @param result 查询结果(具体字段参考MASearchResult类中的定义)
 */
-(void)gpsOffsetSearch:(MARGCSearchOption*)gpsOffSearchOption Result:(MARGCSearchResult*)result;

/*!
 @brief 地理编码查询回调函数
 @param geoCodingSearchOption 发起地理编码查询的查询选项(具体字段参考MASearchOption类中的定义)
 @param result 查询结果(具体字段参考MASearchResult类中的定义)
 */
-(void)geoCodingSearch:(MAGeoCodingSearchOption*)geoCodingSearchOption Result:(MAGeoCodingSearchResult*)result;

/*!
 @brief 逆地理编码查询回调函数
 @param geoCodingSearchOption 发起逆地理编码查询的查询选项(具体字段参考MASearchOption类中的定义)
 @param result 查询结果(具体字段参考MASearchResult类中的定义
 */
-(void)reverseGeocodingSearch:(MAReverseGeocodingSearchOption*)geoCodingSearchOption Result:(MAReverseGeocodingSearchResult*)result;

@end

