#pragma once
#include "BaseBox.h"

#define VMHD_VERSION_SIZE			1
#define VMHD_FLAGS_SIZE				3
#define VMHD_GRAPHICSMODE_SIZE		4
#define VMHD_OPCOLOR_SIZE			4

/************************************************************************************************************
							Video Media Header Box（vmhd）

version					1					box版本，0或1，一般为0。（以下字节数均按version=0）
flags					3				
graphics mode			4					视频合成模式，为0时拷贝原始图像，否则与opcolor进行合成
opcolor					2×3				｛red，green，blue｝

************************************************************************************************************/
class VmhdBox : public BaseBox
{
public:
	VmhdBox();
	~VmhdBox();

	virtual int ParseAttrs(byteptr &pData);

	static BaseBox* CreateObject();

public:
	int				m_iVersion;
	int				m_iFlags;
	int				m_iGraphicsMode;
	int				m_iRed;
	int				m_iGreen;
	int				m_iBlue;
};
