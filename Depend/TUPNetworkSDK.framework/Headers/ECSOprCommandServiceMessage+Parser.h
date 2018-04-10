#import <Foundation/Foundation.h>
#import "ECSOprCommandServiceMessage.h"
#import "ECSBaseMsg+Parser.h"
@interface ECSOprCommand(Parser)
- (void) parseMsg:(mip::msg::OprCommand&) msg;
- (id) initWithMsg:(const mip::msg::OprCommand*) pMsg;
@end

@interface ECSOprCommandAck(Parser)

- (id) initWithMsg:(const mip::msg::OprCommandAck*) pMsg;
- (void) parseMsg:(mip::msg::OprCommandAck&) msg;

@end

@interface ECSOprCommandNotify(Parser)

- (id) initWithMsg:(const mip::msg::OprCommandNotify*) pMsg;
- (void) parseMsg:(mip::msg::OprCommandNotify&) msg;

@end

@interface ECSGetMuteForMobile(Parser)

- (void) parseMsg:(mip::msg::GetMuteForMobile&) msg;
- (id) initWithMsg:(const mip::msg::GetMuteForMobile*) pMsg;

@end

@interface ECSSetMuteForMobileAck(Parser)

- (id) initWithMsg:(const mip::msg::SetMuteForMobileAck*) pMsg;
- (void) parseMsg:(mip::msg::SetMuteForMobileAck&) msg;

@end

@interface ECSSetMuteForMobile(Parser)

- (void) parseMsg:(mip::msg::SetMuteForMobile&) msg;
- (id) initWithMsg:(const mip::msg::SetMuteForMobile*) pMsg;

@end

@interface ECSGetMuteForMobileAck(Parser)

- (id) initWithMsg:(const mip::msg::GetMuteForMobileAck*) pMsg;
- (void) parseMsg:(mip::msg::GetMuteForMobileAck&) msg;

@end
