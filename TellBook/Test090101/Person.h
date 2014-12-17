//
//  Person.h
//  TellBook
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Person : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * tel;
@property (nonatomic, retain) NSData * imageData;
@property (nonatomic, retain) NSString * firstN;

@end
