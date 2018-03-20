Pod::Spec.new do |s|
  s.name         = "SendBirdDesk"
  s.version      = "1.0.1-zendesk"
  s.summary      = "SendBird Desk iOS Framework"
  s.description  = "Integrate SendBird into Zendesk and support your customers live."
  s.homepage     = "https://desk.sendbird.com"
  s.license      = "Commercial"
  s.author       = { "Jed Gyeong" => "jed.gyeong@sendbird.com" }
  s.source       = { :git => "https://github.com/smilefam/SendBird-Desk-iOS-Framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "8.0"
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'SendBirdDesk.framework'
  s.ios.frameworks = ["UIKit", "AVFoundation", "AVKit", "UserNotifications"]

  s.dependency 'SendBirdSDK'
end
