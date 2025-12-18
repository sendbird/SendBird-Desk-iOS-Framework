Pod::Spec.new do |s|
  s.name         = "SendBirdDesk"
  s.version      = "1.1.13"
  s.summary      = "SendBird Desk iOS Framework"
  s.homepage     = "https://sendbird.com"
  s.license      = "Commercial"
  s.author       = { 
    "Jed Gyeong" => "jed.gyeong@sendbird.com", 
    "Tez Park" => "tez.park@sendbird.com",  
    'Sendbird' => 'sha.sdk_deployment@sendbird.com',
    'Celine Moon' => 'celine.moon@sendbird.com',
    "Damon Park" => "damon.park@sendbird.com",
    "Young Hwang" => "young.hwang@sendbird.com",
    "Kai Lee" => "kai.lee@sendbird.com"
  }
  s.source       = { :git => "https://github.com/sendbird/SendBird-Desk-iOS-Framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "13.0"
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'SendBirdDesk.xcframework'
  s.ios.frameworks = ["UIKit", "AVFoundation", "AVKit", "UserNotifications"]

  s.dependency 'SendbirdChatSDK', ">= 4.35.0"
end
