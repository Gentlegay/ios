/*
 *  MTAsyncSaerchResult.h
 *  iMapSDKLib
 *
 *  Created by yin cai on 11-8-30.
 *  Copyright 2011 AutoNavi. All rights reserved.
 *
 */

/*!
 @brief POI 信息类，继承自NSObject类。用于存储 POI 的相关信息，例如，地址、名称、类型等。
 */
@interface MAPOI : NSObject

/*!
 @brief POI点地址
 */
@property(nonatomic,retain) NSString* address;

/*!
 @brief POI点名称
 */
@property(nonatomic,retain) NSString* name;

/*!
 @brief POI点类型
 */
@property(nonatomic,retain) NSString* type;

/*!
 @brief POI点相关URL地址
 */
@property(nonatomic,retain) NSString* url;

/*!
 @brief 唯一编号
 */
@property(nonatomic,retain) NSString* pguid;

/*!
 @brief POI点电话号码
 */
@property(nonatomic,retain) NSString* tel;

/*!
 @brief 经度坐标
 */
@property(nonatomic,retain) NSString* x;

/*!
 @brief 纬度坐标
 */
@property(nonatomic,retain) NSString* y;

/*!
 @brief 周边搜索时,距离中心点距离
 */
@property(nonatomic,retain) NSString* distance;

/*!
 @brief 驾车距离
 */
@property(nonatomic,retain) NSString* driverDistance;

/*!
 @brief 匹配度
 */
@property(nonatomic,retain) NSString* match;

/*!
 @brief 区域代码
 */
@property(nonatomic,retain) NSString* code;

@end

/*!
 @brief POI 查询结果类，继承自NSObject类。用于存储 POI 的查询结果，例如，查询到的 POI 记录数等。
 */
@interface MAPoiSearchResult : NSObject

/*!
 @brief 允许返回记录数与用户权限有关系
 */
@property(nonatomic,assign) NSInteger count;

/*!
 @brief 当前返回记录数
 */
@property(nonatomic,assign) NSInteger record;

/*!
 @brief 总记录数
 */
@property(nonatomic,assign) NSInteger total;

/*!
 @brief 返回的MPOI对象的序列
 */
@property(nonatomic,retain) NSArray*  pois;

@end

/*!
 @brief 网络导航信息类，继承自NSObject类。
 */
@interface MARoute : NSObject

/*!
 @brief 道路名称
 */
@property(nonatomic,retain) NSString* roadName;

/*!
 @brief 方向
 */
@property(nonatomic,retain) NSString* direction;

/*!
 @brief 行驶距离
 */
@property(nonatomic,retain) NSString* roadLength;

/*!
 @brief 辅助动作
 */
@property(nonatomic,retain) NSString* action;

/*!
 @brief 动作
 */
@property(nonatomic,retain) NSString* accessorialInfo;

/*!
 @brief 行驶时间
 */
@property(nonatomic,retain) NSString* driveTime;

/*!
 @brief 道路等级
 */
@property(nonatomic,retain) NSString* grade;

/*!
 @brief 道路描述
 */
@property(nonatomic,retain) NSString* form;

/*!
 @brief 行驶路段坐标 格式(x1,y1)
 */
@property(nonatomic,retain) NSString* coor;

/*!
 @brief 本段道路行驶描述
 */
@property(nonatomic,retain) NSString* textInfo;

@end

/*!
 @brief 途经城市信息类，继承自NSObject类。用于描述途经城市的信息。
 */
@interface MARouteCity : NSObject

/*!
 @brief 城市名
 */
@property(nonatomic,retain) NSString* cityName;

/*!
 @brief 城市英文名
 */
@property(nonatomic,retain) NSString* cityEnglishName;

/*!
 @brief 地区代码
 */
@property(nonatomic,retain) NSString* code;

/*!
 @brief 电话区号
 */
@property(nonatomic,retain) NSString* telnum;

@end

/*!
 @brief 网络导航查询结果类，继承自NSObject类。用于存储网络导航查询的结果信息。
 */
@interface MARouteSearchResult : NSObject

/*!
 @brief 导航段数
 */
@property(nonatomic,assign) NSInteger count;

/*!
 @brief 外包矩形范围
 */
@property(nonatomic,retain) NSString* bounds;

/*!
 @brief 搜索时间
 */
@property(nonatomic,retain) NSString* searchtime;

/*!
 @brief 行驶路段坐标串 格式(x1,y1,x2,y2,x3,y3....)
 */
@property(nonatomic,retain) NSString* coors;

/*!
 @brief MARoute对象数组，存储返回的路段信息
 */
@property(nonatomic,retain) NSArray*  routes;

/*!
 @brief 导航距离
 */
@property(nonatomic,retain) NSString* length;

/*!
 @brief 途经城市 MARouteCity对象数组
 */
@property(nonatomic,retain) NSArray* viaCities;

@end

/*!
 @brief 距离查询结果类，继承自NSObject类。用于存储距离查询的结果信息。
 */
@interface MADistanceSearchResult : NSObject

/*!
 @brief 距离
 */
@property(nonatomic,retain) NSString* distance;

@end

/*!
 @brief 公交换乘段信息类，继承自NSObject类。用于记录每个公交换乘段的具体信息。
 */
@interface MASegment : NSObject

/*!
 @brief 起始站名称
 */
@property(nonatomic,retain) NSString* startName;

/*!
 @brief 终到站名称
 */
@property(nonatomic,retain) NSString* endName;

/*!
 @brief 公交名称
 */
@property(nonatomic,retain) NSString* busName;

/*!
 @brief 途经站名称
 */
@property(nonatomic,retain) NSString* passDepotName;

/*!
 @brief 行驶距离
 */
@property(nonatomic,retain) NSString* driverLength;

/*!
 @brief 步行距离
 */
@property(nonatomic,retain) NSString* footLength;

/*!
 @brief 途经站名称
 */
@property(nonatomic,retain) NSString* passDepotCount;

/*!
 @brief 途径线路坐标串
 */
@property(nonatomic,retain) NSString* coordinateList;

/*!
 @brief 途经站点坐标
 */
@property(nonatomic,retain) NSString* passDepotCoordinate;

@end

/*!
 @brief 公交信息类，继承自NSObject类。返回公交导航查询信息。
 */

@interface MABus : NSObject

/*!
 @brief MASegment对象序列
 */
@property(nonatomic,retain) NSArray* segmentArray;

/*!
 @brief 换乘步行长度
 */
@property(nonatomic,retain) NSString* footEndLength; 

/*!
 @brief 外包矩形范围
 */
@property(nonatomic,retain) NSString* bounds;        

/*!
 @brief 费用
 */
@property(nonatomic,retain) NSString* expense;       

@end

/*!
 @brief 公交导航查询结果类，继承自NSObject类。用于存储公交导航查询的结果信息。
 */
@interface MABusRouteSearchResult : NSObject

/*!
 @brief 导航段数
 */
@property(nonatomic,assign) NSInteger count;      

/*!
 @brief 查询时间
 */
@property(nonatomic,retain) NSString* searchtime; 

/*!
 @brief MABus数组,用来存储MABus对象序列
 */
@property(nonatomic,retain) NSArray*  routes;

@end

/*!
 @brief 公交线路信息类，继承自NSObject类。
 */
@interface MABusLine : NSObject

/*!
 @brief 路线长度(单位:公里)
 */
@property(nonatomic,retain) NSString* length; 

/*!
 @brief 线路名称
 */
@property(nonatomic,retain) NSString* name; 

/*!
 @brief 线路类型 比如：普通公交、地铁等
 */
@property(nonatomic,retain) NSString* type; 

/*!
 @brief 线路状态  0：停止，1：普通
 */
@property(nonatomic,retain) NSString* status; 

/*!
 @brief 线路唯一id标识
 */
@property(nonatomic,retain) NSString* line_id; 

/*!
 @brief 路线名称的关键部分
 */
@property(nonatomic,retain) NSString* key_name; 

/*!
 @brief 始发站名称
 */
@property(nonatomic,retain) NSString* front_name; 

/*!
 @brief 终点站名称
 */
@property(nonatomic,retain) NSString* terminal_name;

/*!
 @brief 首班发车时间 格式初定为”HHMM”,时间为24小时制(0000--2359)
 */
@property(nonatomic,retain) NSString* start_time; 

/*!
 @brief 末班发车时间 格式初定为”HHMM”,时间为24小时制(0000--2359)
 */
@property(nonatomic,retain) NSString* end_time;   

/*!
 @brief 公交公司名称
 */
@property(nonatomic,retain) NSString* company;    

/*!
 @brief 基本价格
 */
@property(nonatomic,retain) NSString* basic_price; 

/*!
 @brief 总价格 当为单一票价的时候，总价格=基本价格
 */
@property(nonatomic,retain) NSString* total_price; 

/*!
 @brief 是否可以使用月票，0：无，1：有
 */
@property(nonatomic,retain) NSString* commutation_ticket; 

/*!
 @brief 是否自动（无人）售票，0：否，1：是
 */
@property(nonatomic,retain) NSString* auto_ticket; 

/*!
 @brief 是否使用电子售票/交通卡，0：否，1：是
 */
@property(nonatomic,retain) NSString* ic_card;     

/*!
 @brief 是否环线，没有起点，没有终点，周而复始，比如地铁环线。0：否，1：是
 */
@property(nonatomic,retain) NSString* loop;        

/*!
 @brief 是否双层，0：否，1：是
 */
@property(nonatomic,retain) NSString* double_deck; 

/*!
 @brief 数据来源，1：自行采集，0：其他
 */
@property(nonatomic,retain) NSString* data_source; 

/*!
 @brief 是否有空调，0：无，1：有
 */
@property(nonatomic,retain) NSString* air;         

/*!
 @brief 线路备注信息
 */
@property(nonatomic,retain) NSString* description; 

/*!
 @brief 线路的平均行驶速度，（目前是以采集到的速度为准）,单位为 km/h
 */
@property(nonatomic,retain) NSString* speed;       

/*!
 @brief 始发站名称拼音
 */
@property(nonatomic,retain) NSString* front_spell; 

/*!
 @brief 终点站名称拼音
 */
@property(nonatomic,retain) NSString* terminal_spell;

/*!
 @brief 服务时间周期描述，例如：夏季线路、周末线路、夜班车等
 */
@property(nonatomic,retain) NSString* service_period;

/*!
 @brief 发车间隔1
 */
@property(nonatomic,retain) NSString* time_interval1;

/*!
 @brief 发车间隔1适用的时间段，起始时间（HHMM）空格截至时间（HHMM）
 */
@property(nonatomic,retain) NSString* interval1; 

/*!
 @brief 发车间隔2
 */
@property(nonatomic,retain) NSString* time_interval2;

/*!
 @brief 发车间隔2适用的时间段，起始时间（HHMM）空格截至时间（HHMM
 */
@property(nonatomic,retain) NSString* interval2;

/*!
 @brief 发车间隔3
 */
@property(nonatomic,retain) NSString* time_interval3;

/*!
 @brief 发车间隔3适用的时间段，起始时间（HHMM）空格截至时间（HHMM）
 */
@property(nonatomic,retain) NSString* interval3; 

/*!
 @brief 发车间隔4
 */
@property(nonatomic,retain) NSString* time_interval4;

/*!
 @brief 发车间隔4适用的时间段，起始时间（HHMM）空格截至时间（HHMM）
 */
@property(nonatomic,retain) NSString* interval4;

/*!
 @brief 发车间隔5
 */
@property(nonatomic,retain) NSString* time_interval5;

/*!
 @brief 发车间隔5适用的时间段，起始时间（HHMM）空格截至时间（HHMM）
 */
@property(nonatomic,retain) NSString* interval5; 

/*!
 @brief 发车间隔6
 */
@property(nonatomic,retain) NSString* time_interval6;

/*!
 @brief 发车间隔6适用的时间段，起始时间（HHMM）空格截至时间（HHMM）
 */
@property(nonatomic,retain) NSString* interval6; 

/*!
 @brief 发车间隔7
 */
@property(nonatomic,retain) NSString* time_interval7;

/*!
 @brief 发车间隔7适用的时间段，起始时间（HHMM）空格截至时间（HHMM）
 */
@property(nonatomic,retain) NSString* interval7; 

/*!
 @brief 发车间隔8
 */
@property(nonatomic,retain) NSString* time_interval8;

/*!
 @brief 发车间隔8适用的时间段，起始时间（HHMM）空格截至时间（HHMM）
 */
@property(nonatomic,retain) NSString* interval8; 

/*!
 @brief 发车信息 用文字来描述无特定发车规则（即发车无规律）的发车信息
 */
@property(nonatomic,retain) NSString* time_desc; 

/*!
 @brief 公共交通线是否路经高速道路，0:否，1：是
 */
@property(nonatomic,retain) NSString* express_way;

/*!
 @brief 途经站点信息描述
 */
@property(nonatomic,retain) NSString* stationDesc;

/*!
 @brief 线路坐标描述信息
 */
@property(nonatomic,retain) NSString* coorDesc; 

@end

/*!
 @brief 公交线路查询结果类，继承自NSObject类。
 */
@interface MABusLineSearchResult : NSObject

/*!
 @brief MABusline对象的序列
 */
@property(nonatomic,retain) NSArray* busLineArray;

/*!
 @brief 允许返回记录数
 */
@property(nonatomic,assign) NSInteger count;      

/*!
 @brief 查询时间
 */
@property(nonatomic,retain) NSString* searchtime; 

/*!
 @brief 当前返回记录数
 */
@property(nonatomic,assign) NSInteger record;     

/*!
 @brief 总记录数
 */
@property(nonatomic,assign) NSInteger total;      

@end

/*!
 @brief 偏移查询结果类，继承自NSObject类。
 */
@interface MARGCItem : NSObject

/*!
 @brief 偏移后的经度坐标
 */
@property(nonatomic,retain) NSString* x; 

/*!
 @brief 偏移后的纬度坐标
 */
@property(nonatomic,retain) NSString* y; 

@end

/*!
 @brief 偏移查询结果数组类，继承自NSObject类。
 */

@interface MARGCSearchResult : NSObject

/*!
 @brief 返回的MARGCItem对象的序列
 */
@property(nonatomic,retain) NSArray* rgcItemArray;

@end

/*!
 @brief 地理兴趣点信息类，继承自NSObject类。
 */
@interface MAGeoPOI : NSObject

/*!
 @brief 名称
 */
@property(nonatomic,retain) NSString* name; 

/*!
 @brief 等级
 */
@property(nonatomic,retain) NSString* level; 

/*!
 @brief 经度坐标
 */
@property(nonatomic,retain) NSString* x;     

/*!
 @brief 纬度坐标
 */
@property(nonatomic,retain) NSString* y;     

/*!
 @brief 地址
 */
@property(nonatomic,retain) NSString* address; 

/*!
 @brief 省份
 */
@property(nonatomic,retain) NSString* province; 

/*!
 @brief 城市
 */
@property(nonatomic,retain) NSString* city;     

/*!
 @brief 区域
 */
@property(nonatomic,retain) NSString* district; 

/*!
 @brief 范围
 */
@property(nonatomic,retain) NSString* range;    

/*!
 @brief 英文名称
 */
@property(nonatomic,retain) NSString* ename;    

/*!
 @brief 英文省份
 */
@property(nonatomic,retain) NSString* eprovince; 

/*!
 @brief 英文城市
 */
@property(nonatomic,retain) NSString* ecity;     

/*!
 @brief 英文区域
 */
@property(nonatomic,retain) NSString* edistrict; 

/*!
 @brief 英文地址
 */
@property(nonatomic,retain) NSString* eaddress;  

@end

/*!
 @brief 地理编码查询结果类，继承自NSObject类。
 */
@interface MAGeoCodingSearchResult : NSObject

/*!
 @brief 返回的记录条数
 */
@property(nonatomic,assign) NSInteger count; 

/*!
 @brief 返回的地理兴趣点(MAGeoPOI对象)队列
 */
@property(nonatomic,retain) NSArray* geoCodingArray; 

@end

/*!
 @brief 省信息类，继承自NSObject类。
 */
@interface MAProvince : NSObject

/*!
 @brief 省份名称
 */
@property(nonatomic,retain) NSString* name;

/*!
 @brief 省份编码
 */
@property(nonatomic,retain) NSString* code;

@end

/*!
 @brief 城市信息类，继承自NSObject类。
 */
@interface MACity : NSObject

/*!
 @brief 城市名称
 */
@property(nonatomic,retain) NSString* name;

/*!
 @brief 城市编码
 */
@property(nonatomic,retain) NSString* code;

/*!
 @brief 电话区号
 */
@property(nonatomic,retain) NSString* tel;

@end

/*!
 @brief 区域信息类，继承自NSObject类。
 */
@interface MADistrict : NSObject

/*!
 @brief 区域名称
 */
@property(nonatomic,retain) NSString* name;

/*!
 @brief 区域编码
 */
@property(nonatomic,retain) NSString* code;

/*!
 @brief 区域中心点经度
 */
@property(nonatomic,retain) NSString* x;

/*!
 @brief 区域中心点纬度
 */
@property(nonatomic,retain) NSString* y;

/*!
 @brief 区域矩形范围
 */
@property(nonatomic,retain) NSString* bounds;

@end

/*!
 @brief 道路信息类，继承自NSObject类。
 */
@interface MARoad : NSObject

/*!
 @brief 道路id
 */
@property(nonatomic,retain) NSString* Id; 

/*!
 @brief 道路名称
 */
@property(nonatomic,retain) NSString* name;

/*!
 @brief 道路英文名称
 */
@property(nonatomic,retain) NSString* ename;

/*!
 @brief 道路宽度
 */
@property(nonatomic,retain) NSString* width;

/*!
 @brief 道路等级
 */
@property(nonatomic,retain) NSString* level;

/*!
 @brief 道路方向
 */
@property(nonatomic,retain) NSString* direction;

/*!
 @brief 距离参数点距离
 */
@property(nonatomic,retain) NSString* distance;

@end

/*!
 @brief 道路交叉口信息类，继承自NSObject类。
 */
@interface MACross : NSObject

/*!
 @brief 交叉口名称
 */
@property(nonatomic,retain) NSString* name;

/*!
 @brief 交叉口经度
 */
@property(nonatomic,retain) NSString* x; 

/*!
 @brief 交叉口纬度
 */
@property(nonatomic,retain) NSString* y; 

@end

/*!
 @brief 逆地理编码信息类，继承自NSObject类。
 */
@interface MAReverseGeocodingInfo : NSObject

/*!
 @brief 省份信息
 */
@property(nonatomic,retain) MAProvince* province;

/*!
 @brief 城市信息
 */
@property(nonatomic,retain) MACity* city;

/*!
 @brief 区信息
 */
@property(nonatomic,retain) MADistrict* district;

/*!
 @brief 道路信息 MARoad对象队列
 */
@property(nonatomic,retain) NSArray* roads;

/*!
 @brief poi信息 MAPOI对象队列
 */
@property(nonatomic,retain) NSArray* pois;

/*!
 @brief 道路交叉口信息
 */
@property(nonatomic,retain) NSArray* crosses;

@end

/*!
 @brief 逆地理编码查询结果类，继承自NSObject类。用于存储逆地理编码信息 MAReverseGeocodingInfo 的集合。
 */
@interface MAReverseGeocodingSearchResult : NSObject

/*!
 @brief 返回的MAReverseGeocodingResult对象序列
 */
@property(nonatomic,retain) NSArray* resultArray; 

@end






