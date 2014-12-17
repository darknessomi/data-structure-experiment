//
//  EditViewController.h
//  TellBook
//


#import <UIKit/UIKit.h>
#import "Person.h"

@interface EditViewController : UIViewController<UITextFieldDelegate,UIImagePickerControllerDelegate,UINavigationControllerDelegate>

@property(strong, nonatomic) Person *person;

@end
