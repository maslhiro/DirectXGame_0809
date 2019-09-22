#include "DeviceManager.h"

DeviceManager* DeviceManager::_instance = nullptr;

DeviceManager::DeviceManager()
{
	_pD3d = NULL;
	_pDevice = NULL;
	_backBuffer = NULL;
	_spriteHandler = NULL;
}

int DeviceManager::init(pGraphic _window)
{
	_pD3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS	l_preParameter;

	ZeroMemory(&l_preParameter, sizeof(l_preParameter));

	l_preParameter.SwapEffect = D3DSWAPEFFECT_DISCARD;
	l_preParameter.Windowed = true;
	l_preParameter.hDeviceWindow = _window->getWnd();
	l_preParameter.BackBufferFormat = D3DFMT_A8R8G8B8;
	l_preParameter.BackBufferCount = 1;

	RECT r;
	GetClientRect(_window->getWnd(), &r);	// retrieve Window width & height 

	l_preParameter.BackBufferHeight = r.bottom + 1;
	l_preParameter.BackBufferWidth = r.right + 1;

	_pD3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		_window->getWnd(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&l_preParameter,
		&_pDevice);

	if (_pDevice == NULL) {
		MessageBox(_window->getWnd(),
			L"Can not create device",
			L"Error :(",
			NULL);
		return 0;
	}

	_pDevice->GetBackBuffer(NULL, NULL, D3DBACKBUFFER_TYPE_MONO, &_backBuffer);

	// Initialize sprite helper from Direct3DX helper library
	D3DXCreateSprite(_pDevice, &_spriteHandler);

	if (_spriteHandler == NULL) {
		MessageBox(_window->getWnd(),
			L"Can not create sprite handler",
			L"Error :(",
			NULL);
		return 0;
	}

	return 1;
}

DeviceManager* DeviceManager::getInstance()
{
	if (_instance == nullptr)
		_instance = new DeviceManager();
	return _instance;
}

DeviceManager::~DeviceManager(void)
{
	if (_spriteHandler != NULL) _spriteHandler->Release();
	if (_backBuffer != NULL) _backBuffer->Release();
	if (_pDevice != NULL) _pDevice->Release();
	if (_pD3d != NULL) _pD3d->Release();

	_pD3d = NULL;
	_pDevice = NULL;
	_backBuffer = NULL;
	_spriteHandler = NULL;
}

void DeviceManager::release()
{
	delete _instance;
	_instance = nullptr;
}

void DeviceManager::present()
{
	this->_pDevice->Present(0, 0, 0, 0);
}


void DeviceManager::clearScreen()
{
	this->_pDevice->ColorFill(_backBuffer, NULL, BACKGROUND_COLOR);
}

DirectDevice DeviceManager::getDevice()
{
	return _pDevice;
}

DirectSurface DeviceManager::getSurface()
{
	return _backBuffer;
}

DirectSurface DeviceManager::getBackBuffer()
{
	return _backBuffer;
}


LPD3DXSPRITE DeviceManager::getSpriteHandler()
{
	return _spriteHandler;
}
