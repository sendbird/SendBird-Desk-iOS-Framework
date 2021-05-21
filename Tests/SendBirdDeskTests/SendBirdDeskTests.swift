import XCTest
import SendBirdDesk

final class SendBirdDeskTests: XCTestCase {
    func testExample() {
        let expectation = expectation(description: "")
        SBDSKTicket.createTicket(withTitle: "", userName: "") { ticket, error in
            XCTAssertNil(ticket)
            expectation.fulfill()
        }
        
        self.wait(for: [expectation], timeout: 5)
    }

    static var allTests = [
        ("testExample", testExample),
    ]
}
