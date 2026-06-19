// swift-tools-version:5.10
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SendBirdDesk",
    platforms: [.iOS(.v13)],
    products: [
        .library(
            name: "SendBirdDesk",
            targets: ["SendBirdDeskTarget"]),
    ],
    dependencies: [
        .package(name: "SendbirdChatSDK",
                 url: "https://github.com/sendbird/sendbird-chat-sdk-ios",
                 from: "4.39.5"),
    ],
    targets: [
        .binaryTarget(
	    name: "SendBirdDesk",
            url: "https://github.com/sendbird/SendBird-Desk-iOS-Framework/releases/download/v1.2.2/SendBirdDesk.xcframework.zip",
            checksum: "4d0ce47abc15bfa53827345b4964dda79fc26ebc6ed4c268edc5bc1eadbc0e18" // SendbirdDesk_CHECKSUM
	),
        .target(name: "SendBirdDeskTarget",
                dependencies: [
                    .target(name: "SendBirdDesk"),
                    .product(name: "SendbirdChatSDK", package: "SendbirdChatSDK")
                ],
                path: "Sources"),
        .testTarget(
            name: "SendBirdDeskTests",
            dependencies: ["SendBirdDeskTarget"]),
    ]
)
