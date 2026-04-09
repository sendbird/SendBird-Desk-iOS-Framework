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
                 from: "4.39.0"),
    ],
    targets: [
        .binaryTarget(
	    name: "SendBirdDesk",
            url: "https://github.com/sendbird/SendBird-Desk-iOS-Framework/releases/download/v1.1.14/SendBirdDesk.xcframework.zip",
            checksum: "79bfaef1be064f0447771fc821882f85c50aeb4b5fd0d814689024c821e9c1dd" // SendbirdDesk_CHECKSUM
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
