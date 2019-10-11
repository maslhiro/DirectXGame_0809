# DirectX Game_0809
:rainbow: Template DirectX Game 08_09

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

---- GameMap.h : Load file .tmx để hiển thị map lên , riêng name của tileset phải đặt trùng với id Texture 

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

|                               |ANIMATION                    |
|-------------------------------|-----------------------------|
|Render            |![render](https://user-images.githubusercontent.com/26876671/65209490-82886c00-dac2-11e9-8d05-cc4414680ca7.gif)|
|Scale , Transform |![scale](https://user-images.githubusercontent.com/26876671/65165855-c733e900-da69-11e9-9b57-3346dda9b7c1.gif)|
|Bounding Box | ![bounding](https://user-images.githubusercontent.com/26876671/65273505-7ac0da00-db4b-11e9-9eca-0e4eccdc2401.gif)|

---
|                               |GAME OBJECT (BILLY)         |
|-------------------------------|-----------------------------|
|Handler Input            |![gif_handlerinput](https://user-images.githubusercontent.com/26876671/65707381-9d587300-e0b6-11e9-95bb-82322df82703.gif)|
|State Machines           |![gif_statemachines](https://user-images.githubusercontent.com/26876671/65783395-e58c9980-e179-11e9-8d91-e933996db132.gif)|