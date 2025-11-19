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
                 from: "4.34.1"),
    ],
    targets: [
        .binaryTarget(
	    name: "SendBirdDesk",
            url: "https://github.com/sendbird/SendBird-Desk-iOS-Framework/releases/download/v1.1.12/SendBirdDesk.xcframework.zip",
            checksum: "a33b41ccd8b237412471864fc9417a0cb4f1a18117e7039dc1729f222b80316f" // SendbirdDesk_CHECKSUM
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
