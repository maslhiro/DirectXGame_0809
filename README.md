# DirectX Game_0809
:rainbow: Template DirectX Game 08_09

Để tạo file map game cũng như trích xuất toạ độ của sprite trong 1 ảnh lớn mình có viết 1 tool để xuât ra file txt : https://github.com/maslhiro/Tmx_Converter_Tool/releases/tag/v4.0

```
-- Main.cpp 

---- Game.h : init , tạo vòng lặp cho game + release các đối tượng khi game
kết thúc

---- DeviceManager.h : (Singleton) tạo các đối tượng directX như DXSPRITE, DEVICE9, SURFACE9.

---- DrawDebug.h: (Singleton) class giúp vẽ các đường thẳng trên màn hình chỉ cần điểm đầu điểm cuối , dộ dày 
line mặc định là 2 và màu line mặc định là đỏ. 

---- Graphic.h : tạo window cho game.

---- InputHandler.h : (Singleton) bắt sự kiện keyboard của game dựa trên 1 hash < int,bool >,  
class này sẽ được init và release ở constructor và destructor của lớp graphic :rainbow: 

---- Gametime.h : (Singleton) quản lí FPS (Frame per Second), tính tổng thời gian trong game.

---- Unit.h : Quy định 1 không gian chứa 1 listgameObj bên trong và Bouding của nó trong map, 
mục đích là để Unit cố thể sử dụng như tileset.

---- FixedGrid.h  : Đọc file txt vừa load thông tin map ( w, h , uW, uH, ... ) vừa đọc thông tin các
gameObj có trong map add vào từng Unit .

---- GameMap_Txt.h : Lấy thôg tin map từ Grid sau đó vẽ các Unit contains với Camera, đồng thời render và 
update các gameObj (có cả Aladdin ) trong map. 

---- Texture.h : (Singleton) load các ảnh resource vào 1 map <int, TEXTURE> quản lí bằng enum id Texture , 
muốn lấy teture nào chỉ việc gọi ra như mảng. EX: _texture[eIdTexture::TANK]

---- Sprite.h: (Singleton) doc vao 1 file txt tọa độ và tạo thành 1 map <int,RectSprite> với RectSprite 
là hình chữ nhật lưu 4 vị trí ( top, bottom, left, right) và idTexture để lớp Animation có thể biết được 
texture nào để cắt sprite ra. Id Sprite cũng được quản lí bằng enum tương tự texture.

---- Animation.h : 1 vector<int> sẽ lưu lại các id sprite khi ta add vào Animation , đồng thời sẽ có 1 vector
để xác định tâm Rect Sprite để vẽ cũng như 1 vector để fix pos vị trí mặc định góc bottom||left
giữa các sprite ( do hầu hết các sprite không bằng nhau) 

---- AnimationManager.h : (Singleton) nơi quản lí tất cả các animation từ load, setTimePerFrame,addSprite,.. 
đều phải khai báo ở đây. Tương tư lớp sprite và texture. 

---- GameObject.h : Lớp cha của tất cả object trong game, cho phép override 4 hàm: 
loadResouce , render, update , handlerInput. Quản lí 1 map state (int) với animation tương ứng.

```
---
