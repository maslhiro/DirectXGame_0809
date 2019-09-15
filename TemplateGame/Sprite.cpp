#include "Sprite.h"

Sprite* Sprite::_instance = nullptr;

Sprite::Sprite()
{
}

void Sprite::init() {

}

Sprite* Sprite::getInstance()
{
	if (_instance == nullptr) {
		_instance = new Sprite();
	}
	return _instance;
}

int Sprite::add(eIdTexture idTexture, const char* fileInfoPath) {
	FILE* file;
	fopen_s(&file, fileInfoPath, "r");

	if (file == NULL) return 0;

	RectSprite rect;
	int idSprite;
	while (!feof(file))
	{
		fscanf_s(file, "%d %d %d %d %d", &idSprite, &rect.left, &rect.top, &rect.right, &rect.bottom);
		// đọc theo định dạng cho trước, các giá trị đọc được sẽ lưu vào các biến ở phía sau
		// Lưu ý sau khi đọc xong "con trỏ đọc file" sẽ được chuyển đến vị trí cuối cùng

		rect.setIdTexture(idTexture);
		_listSprite[idSprite] = rect;
		rect.release();
	}
	fclose(file);

	_RPT0(0, "[INFO] Load List Rect Done\n");
	return 1;
}

RectSprite Sprite::get(eIdSprite idSprite)
{
	return _listSprite[idSprite];
}
