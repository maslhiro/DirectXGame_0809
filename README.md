# DirectX Game_0809
:rainbow: Template DirectX Game 08_09

```
-- Main.cpp 

---- Game.h : init , tạo vòng lặp cho game

---- DeviceManager.h : (Singleton) tạo các đối tượng directX như DXSPRITE, DEVICE9, SURFACE9.

---- Graphic.h : tạo window cho game.

---- InputHandler.h : bắt sự kiện keyboard của game , dựa trên 1 hash < int,bool >

---- Gametime.h : (Singleton) quản lí FPS (Frame per Second), tính tổng thời gian trong game.

---- Texture.h : (Singleton) load các ảnh resource chuyển thành các texture directx

để các Animation cắt texture này làm sprite,không phải load nhiều ảnh.

---- Sprite.h: (Singleton) load các file txt tọa độ sprite đi kèm với các ảnh resource sau đó

 map thành 1 hash, riêng tọa độ các ảnh sẽ được lưu thành 1 RectSprite chưa thêm thông tin 

về base texture nó được cắt.

---- Animation.h : lưu lại vector<idSprite> và timePerFrame của animation, RectSprite sẽ được
chuyển thành texture được render và update theo timePerFrame. Đã update anchor ( điểm neo )
để render vị trí giữa sprite , nếu để NULL => mặc định anchor tọa độ là  top, left :(


---- AnimationManager.h : (Singleton) quản lí tất cả các animation, tương tự như Sprite 
có thể get và add Animation theo Id

```
---

|                               |ANIMATION                    |
|-------------------------------|-----------------------------|
|Render            |![giphy (1)](https://user-images.githubusercontent.com/26876671/65209490-82886c00-dac2-11e9-8d05-cc4414680ca7.gif)|
|Scale , Transform |![giphy](https://user-images.githubusercontent.com/26876671/65165855-c733e900-da69-11e9-9b57-3346dda9b7c1.gif)|
|Bounding Box | ![giphy (2)](https://user-images.githubusercontent.com/26876671/65273505-7ac0da00-db4b-11e9-9eca-0e4eccdc2401.gif)
|
