# [English Below]
## Hệ thống quản lý ngân hàng.
## Đây là bài cáo cáo môn lập trình hướng đối tượng của tôi.
### Chương trình được chạy trên Cli với các chức năng khác nhau ( CRUD, chuyển tiền,.....) (Xem ảnh).
### Công nghệ sử dụng 100% C++.
### Yêu cầu hệ thống: Có bộ phiên dịch gcc và chạy với tiêu chuẩn C++11 hoặc cao hơn
### Cách chạy chương trình: Mở terminal và thực thi file Source.cpp

Hệ thống được mô tả quy trình thực hiện như sau:

Chia hệ thống thành 2 cấp: User & Admin, mỗi cấp sẽ có chức năng khác nhau (admin sẽ có nhiều chức năng hơn user)

Khi chạy chương trình sẽ yêu cầu đăng nhập, ta lấy thông tin đăng nhập trong file Account.txt

Sau khi đăng nhập ta sẽ test từng tính năng, nếu không biết thì bạn có thể tra google tên của chức năng.

Tính năng chuyển khoản sẽ sử dụng số điện thoại để chuyển tiền qua lại (Tôi biết là tôi có thuộc tính số tài khoản nhưng mà tôi lỡ làm rồi =)))) các bạn có thể chính lại nếu muốn)

Dữ liệu lưu lịch sử chuyển khoản sẽ đc lưu ở file transaction.txt. Dữ liệu này sẽ bao gồm số điện thoại của người gửi, số điện thoại của người nhận và số tiền chuyển khoản

Dữ liệu lưu tài khoản sẽ đc lưu ở file Account.txt. Dữ liệu này sẽ gồm tên đăng nhập, mật khẩu và chức vụ (admin/user)

Dữ liệu lưu thông tin cá nhân của admin & user sẽ đc lưu ở file Data.txt. Dữ liệu này thì gồm các thông tin của chủ sở hữu

Nếu bạn không biết cách làm cho Text Editor/IDE của các bạn chạy chuẩn C++11 thì đây là cách bạn có thể tham khảo:

Config C++11 in VSCode: https://stackoverflow.com/questions/53995830/compiling-c11-in-visual-studio-code

Config C++11 in DevC/C++: https://stackoverflow.com/questions/16951376/how-to-change-mode-from-c98-mode-in-dev-c-to-a-mode-that-supports-c0x-ran

Phương án mở rộng chương trình trong tương lai:

- Tối ưu hóa code
- Tối ưu hóa giao diện 
- Tối ưu hoá dữ liệu lưu trữ
- Tính năng đổi mật khẩu/ quên mật khẩu
- Tính năng lưu ngày tháng năm khi chuyển khoản
- Tính năng đăng ký tài khoản mới mà không cần phải vào chương trình với quyền admin

Ở dưới là một số biểu đồ các bạn có thể dễ dàng hình dung
__________________________________________________________________________________________
# Bank Management System

## This is my OOP assignment

### This app is run on Cli & has multiple features: CRUD Users; deposit & withdraw and save transaction history (See class diagram)

### Technologie: 100% C++ with a lot of OOP basic skills

### System requirements: Your PC must have g++ compiler installed and C++11 or higher

### How to run: Open your terminal and run Source.cpp file

The system is described as follows:

Divide the system into two levels: User & Admin. Each level will have different functions (admin will have more methods than users)

When running, the program will ask for login, and we get the login information in the file Account.txt

After logging in, we can run each feature. If you don't know, you can google the function's name.

The transfer feature will use the phone number to transfer money back and forth (I know I have the account number attribute, but I did it by mistake =)))) you can correct it if you want)

Transfer history data will be saved in transaction.txt. This data includes the sender's phone number, the recipient's phone number, and the transfer amount.

Account saved data will be kept in the file Account.txt. This data will include username, password, and position (admin/user).

Data to save the personal information of admin & user will be saved in Data.txt file. This data includes the information of the owner

If you don't know how to make your Text Editor/IDE run standard C++11, here's how you can refer:

Config C++11 in VSCode: https://stackoverflow.com/questions/53995830/compiling-c11-in-visual-studio-code

Config C++11 in DevC/C++: https://stackoverflow.com/questions/16951376/how-to-change-mode-from-c98-mode-in-dev-c-to-a-mode-that- supports-c0x-ran

Plans to expand the program in the future:
- Code optimization
- Optimized interface
- Optimized data storage
- Password change/forgot password feature
- The feature to save the date when transferring money
- New account registration feature without having to enter the program with admin rights

Below are some charts you can easily visualize:
