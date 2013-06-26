//
//  IndexViewController.m
//  njbike
//
//  Created by suny on 13-4-22.
//  Copyright (c) 2013年 suny. All rights reserved.
//

#import "IndexViewController.h"
#import "MAGeometry.h"


@interface IndexViewController ()
{
     NSMutableDictionary *pointArray;
     NSMutableArray *parr;
    CLLocationCoordinate2D locationOld;
}
    

@end

@implementation IndexViewController
@synthesize ico = _ico,today=_today,weather=_weather,temperature=_temperature,myMapView=_myMapView,stratTime=_stratTime,endBtu=_endBtu,endTime=_endTime,overlays = _overlays;


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
   
    //地图
    _map = [[MAMapView alloc] initWithFrame:CGRectMake(0,0,0,0)];
    _map.mapType = MAMapTypeStandard;
    _map.showsUserLocation = YES;
    _map.delegate = self;
    parr =[[NSMutableArray alloc] init];
    

    
    //设置logo边框
    CALayer * layer = [_ico layer];
    layer.borderColor = [
                         [UIColor whiteColor] CGColor];
    layer.borderWidth = 2.0f;
    [layer setCornerRadius:10.0];
    _ico.contentMode=UIViewContentModeScaleAspectFit;
    _ico.clipsToBounds = YES;
    
    //天气
    NSDictionary* weatherXml = [IndexViewController getWeatherXmlForZipCode:@"101190101"];
    
    _today.text = [weatherXml objectForKey:@"date_y"];
    _weather.text=[weatherXml objectForKey:@"weather1"];
    _temperature.text=[weatherXml objectForKey:@"temp1"];
    
    //creat file
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *docPath = [paths objectAtIndex:0];
    myFile = [docPath stringByAppendingPathComponent:@"loction.plist"];
    NSDictionary* dic2 = [NSDictionary dictionaryWithContentsOfFile:myFile];
    //操作plist
    if(dic2 == nil)
    {
        NSFileManager* fm = [NSFileManager defaultManager];
        [fm createFileAtPath:myFile contents:nil attributes:nil];
    }
    NSLog(@"%@",docPath);

    
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [_ico setImage:[UIImage imageNamed:@"ico.png"]];
    [_myMapView addSubview:_map];
    
   

}


- (MAOverlayView *)mapView:(MAMapView *)mapView viewForOverlay:(id <MAOverlay>)overlay
{
 
        MAPolylineView *polylineView = [[MAPolylineView alloc] initWithPolyline:overlay];
        
        polylineView.lineWidth   = 5.f;
        polylineView.strokeColor = [UIColor colorWithRed:0 green:0 blue:1 alpha:1];
        
        return polylineView;
}

- (void)mapView:(MAMapView *)mapView didUpdateUserLocation:(MAUserLocation *)userLocation
{
      
    //数据初始化
    CLLocationCoordinate2D location=userLocation.location.coordinate;
   
    
    
    if([parr count]==0){
        mapView.region =  MACoordinateRegionMake(location,
                                                 MACoordinateSpanMake(0.05, 0.05));
        NSMutableDictionary *ptDicFirst =  [NSMutableDictionary dictionary];
        [ptDicFirst setValue:[NSNumber numberWithDouble:location.latitude] forKey:@"latitude"];
        [ptDicFirst setValue:[NSNumber numberWithDouble:location.longitude] forKey:@"longitude"];
        locationOld = location;
                
        [parr addObject:ptDicFirst];
        [parr writeToFile:myFile atomically:YES];
         NSLog(@"%@",parr);
    }

    
   
   
    

   
    NSMutableDictionary *ptDic =  [NSMutableDictionary dictionary];
    [ptDic setValue:[NSNumber numberWithDouble:location.latitude] forKey:@"latitude"];
    [ptDic setValue:[NSNumber numberWithDouble:location.longitude] forKey:@"longitude"];
    
   
    if([parr count] >0){
        CLLocationCoordinate2D polylineCoords[[parr count]];
        
        
        for (int i=0;i<[parr count];i++){
            //CLLocationCoordinate2D s ;
            NSMutableDictionary *ptDic = [parr objectAtIndex:i];
            NSDecimalNumber *nsLatiude = [ptDic objectForKey:@"latitude"];
            NSDecimalNumber *longitude = [ptDic objectForKey:@"longitude"];
            
            polylineCoords[i].latitude = [nsLatiude doubleValue];
            polylineCoords[i].longitude = [longitude doubleValue];
            
            if(i==([parr count]-1)){
                locationOld.latitude=[nsLatiude doubleValue];
                locationOld.longitude = [longitude doubleValue];
            }
            
        }
        
        //判断走的距离有没有超过5米
        MAMapPoint centerMapPoint = MAMapPointForCoordinate(location);
        MAMapPoint centerMapPointOld = MAMapPointForCoordinate(locationOld);
        double a = MAMetersBetweenMapPoints(centerMapPoint,centerMapPointOld);
        if(a>10){
            
            mapView.region =  MACoordinateRegionMake(location,
                                                     MACoordinateSpanMake(0.05, 0.05));
            [parr addObject:ptDic];
            
            //写入文件
            
            [parr writeToFile:myFile atomically:YES];
            
            for (int i=0;i<[parr count];i++){
                //CLLocationCoordinate2D s ;
                NSMutableDictionary *ptDic = [parr objectAtIndex:i];
                NSDecimalNumber *latiude = [ptDic objectForKey:@"latitude"];
                NSDecimalNumber *longitude = [ptDic objectForKey:@"longitude"];
                
                polylineCoords[i].latitude = [latiude doubleValue];
                polylineCoords[i].longitude = [longitude doubleValue];
                
                if(i==([parr count]-1)){
                    locationOld.latitude=[latiude doubleValue];
                    locationOld.longitude = [longitude doubleValue];
                }
                
            }
            
            
            MAPolyline *polyline = [MAPolyline polylineWithCoordinates:polylineCoords
                                                                 count:[parr count]];
           
            
            [_map insertOverlay:polyline atIndex:0];

           
        }

    }
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)startRiding:(id)sender {
    NSDate* date = [NSDate date];
    
    NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
    
    [formatter setDateFormat:@"HH:MM:SS"];
    
    NSString* str = [formatter stringFromDate:date];
    _stratTime.text=str;
    [_endBtu setHidden:NO];
    [sender setHidden:YES];
}

- (IBAction)endRiding:(id)sender {
    NSDate* date = [NSDate date];
    
    NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
    
    [formatter setDateFormat:@"HH:MM:SS"];
    
    NSString* str = [formatter stringFromDate:date];
    _endTime.text=str;
    
    //会话ge
    UIAlertView *alert=[[UIAlertView alloc] initWithTitle:nil message:@"给你的旅程起个名字吧" delegate:self cancelButtonTitle:@"确定" otherButtonTitles:nil,nil];
    alert.alertViewStyle=UIAlertViewStylePlainTextInput;
    [alert show];
    
}

- (void) alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self performSegueWithIdentifier:@"record" sender:self];
}



+(NSDictionary*)getWeatherXmlForZipCode: (NSString*)zipCode {
    NSError *error;
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL: [NSURL URLWithString: [NSString stringWithFormat:@"http://m.weather.com.cn/data/%@.html", zipCode]]];
    NSData *dataResponse = [NSURLConnection sendSynchronousRequest: request returningResponse: nil error: nil];
    NSDictionary *dictionaryWeather = [NSJSONSerialization JSONObjectWithData: dataResponse options: NSJSONReadingMutableLeaves error: &error];
    NSDictionary *dictionaryWeatherInfo = [dictionaryWeather objectForKey: @"weatherinfo"];
    return dictionaryWeatherInfo;
}


@end
