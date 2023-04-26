// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SendBirdDesk",
    platforms: [.iOS(.v11)],
    products: [
        .library(
            name: "SendBirdDesk",
            targets: ["SendBirdDeskTarget"]),
    ],
    dependencies: [
        .package(name: "SendbirdChatSDK",
                 url: "https://github.com/sendbird/sendbird-chat-sdk-ios",
                 from: "4.6.7"),
    ],
    targets: [
        .binaryTarget(name: "SendBirdDesk", path: "SendBirdDesk.xcframework"),
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
