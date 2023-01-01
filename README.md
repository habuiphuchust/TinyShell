
# TinyShell
project1_ Nguyên lý hệ điều hành_ Phạm Đăng Hải
Mô tả:
- TinyShell được viết bằng dev C++, mục đích tìm hiểu 1 số hàm quản lý tiến trình winapi
- Đã chạy thử trên win 11
- Gồm các lệnh:
+ date : lấy ngày
+ time : lấy thời gian
+ help : hướng dẫn sử dụng
+ list : in ra danh sách tiến trình 
+ create [tên tiến trình] [f|b] : tạo tiến trình về chế độ foreground|background
+ kill [id tiến trình] : dừng tiến trình
+ stop [id tiến trình] : dừng tiến trình
+ resume [id tiến trình] : tiếp tục tiến trình
+ path : xem biến môi trường
+ addpath [tên biến mới] : đặt lại biến môi trường
+ exit : kết thúc
-	Shell chạy được file *.bat sử dụng các lệnh trên
Hướng dẫn cài đặt:
-	Chạy file TinyShell.exe
-	Biến môi trường mặc định: application/
-	Các file exe, bat demo trong thư mục application, nên để cùng thư mục TinyShell.exe
