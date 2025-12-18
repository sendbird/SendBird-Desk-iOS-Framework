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
                 from: "4.35.0"),
    ],
    targets: [
        .binaryTarget(
	    name: "SendBirdDesk",
            url: "https://github.com/sendbird/SendBird-Desk-iOS-Framework/releases/download/v1.1.13/SendBirdDesk.xcframework.zip",
            checksum: "403cf658bc4e785b818dc8e10bb70572363920955ec7ee54bfd08d9e1010094e" // SendbirdDesk_CHECKSUM
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
