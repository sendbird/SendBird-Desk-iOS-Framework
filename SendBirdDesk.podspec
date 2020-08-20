Pod::Spec.new do |s|
  s.name         = "SendBirdDesk"
  s.version      = "1.0.9"
  s.summary      = "SendBird Desk iOS Framework"
  s.description  = "SendBird Desk iOS Framework"
  s.homepage     = "https://desk.sendbird.com"
  s.license      = "Commercial"
  s.author       = { "Jed Gyeong" => "jed.gyeong@sendbird.com", "Tez Park" => "tez.park@sendbird.com", "Minhyuk Kim" => "minhyuk.kim@sendbird.com" }
  s.source       = { :git => "https://github.com/sendbird/SendBird-Desk-iOS-Framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "8.0"
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'SendBirdDesk.framework'
  s.ios.frameworks = ["UIKit", "AVFoundation", "AVKit", "UserNotifications"]

  s.dependency 'SendBirdSDK'
end
