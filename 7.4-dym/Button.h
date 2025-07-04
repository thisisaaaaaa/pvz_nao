#pragma once
#include<graphics.h>

//这个文件夹中包含了按钮基类，还有所有类型的按钮


class Button
{
public:
	Button(RECT rect, LPCTSTR path_img_idle, LPCSTR path_img_hovered);

	~Button() = default;

	void ProcessEvent(const ExMessage& msg);
	void Draw();

protected:
	virtual void OnClick() = 0;

private:
	enum class Status
	{
		Idle = 0,
		Hovered,
		Pushed
	};
	RECT region;
	IMAGE img_idle;
	IMAGE img_hovered;
	Status status = Status::Idle;

	bool CheckCursorHit(int x, int y)
	{
		return x >= region.left && x <= region.right && y >= region.top && y <= region.bottom;
	}
};

class startButton :public Button
{
public:
	startButton(RECT rect, LPCTSTR path_img_idle, LPCSTR path_img_hovered) :Button(rect, path_img_idle, path_img_hovered) {};
	~startButton() = default;
	void OnClick();

	bool is_game_started = false;

}; 
