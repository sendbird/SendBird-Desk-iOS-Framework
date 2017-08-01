Pod::Spec.new do |s|
  s.name         = "SendBirdDesk"
  s.version      = "0.9.9"
  s.summary      = "SendBird Desk iOS Framework"
  s.description  = "Integrate SendBird into Zendesk and support your customers live."
  s.homepage     = "https://desk.sendbird.com"
  s.license      = "Commercial"
  s.author       = { "Jed Gyeong" => "jed.gyeong@sendbird.com" }
  s.source       = { :git => "https://github.com/smilefam/SendBirdDesk-iOS-Framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "8.0"
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'SendBirdDesk.framework'
  s.ios.frameworks = ["UIKit", "AVFoundation", "AVKit"]

  s.dependency 'SendBirdSDK', '>= 3.0.61'
  s.dependency 'AFNetworking', '>= 3.1.0'
  s.dependency 'FLAnimatedImage', '>= 1.0.12'
  s.dependency 'NYTPhotoViewer', '>= 1.2.0'
  s.dependency 'TOCropViewController', '>= 2.0.12'
  s.dependency 'HTMLKit', '>= 2.0.6'
end
