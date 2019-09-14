# DirectX Game_0809
:rainbow: Template DirectX Game 08_09

```
-- Main.cpp 

---- Game.h : init , tạo vòng lặp cho game

---- DeviceManager.h : (Singleton) tạo các đối tượng directX như LPD3DXSPRITE, LPDIRECT3DDEVICE9, LPDIRECT3DSURFACE9 . 

---- Graphic.h : tạo window cho game.

---- Gametime.h : (Singleton) quản lí FPS (Frame per Second), tính tổng thời gian trong game.

---- GameObject.h : abstract class  quản lí LPDIRECT3DTEXTURE9, pos của mỗi object trong game.

---- Texture.h : (Singleton) load list resource sprite ( image ) chuyển thành DirectXTexture để các ObjGame cắt texture này làm sprite, không phải load nhiều ảnh để tạo texture cho từng ObjGame riêng.

```
