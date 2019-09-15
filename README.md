# DirectX Game_0809
:rainbow: Template DirectX Game 08_09

```
-- Main.cpp 

---- Game.h : init , tạo vòng lặp cho game

---- DeviceManager.h : (Singleton) tạo các đối tượng directX như DXSPRITE, DEVICE9, SURFACE9.

---- Graphic.h : tạo window cho game.

---- Gametime.h : (Singleton) quản lí FPS (Frame per Second), tính tổng thời gian trong game.

---- Texture.h : (Singleton) load các ảnh resource chuyển thành các texture directx

để các sprite cắt texture này làm sprite,không phải load nhiều ảnh.

---- Sprite.h: (Singleton) load các file txt tọa độ sprite đi kèm với các ảnh resource sau đó

 map thành 1 hash, riêng tọa độ các ảnh sẽ được lưu thành 1 RectSprite chưa thêm thông tin 

về base texture nó được cắt.

```
