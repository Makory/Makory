// BmpToArray.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "BmpToArray.h"


// BmpToArray

IMPLEMENT_DYNAMIC(BmpToArray, CWnd)

BmpToArray::BmpToArray()
{

}

BmpToArray::~BmpToArray()
{
}

void BmpToArray::LoadBmp(LPCTSTR lpszPathName){
		
	CFile infile;
	CFileException e;
	CString fileName;
	fileName.Format(lpszPathName);		//�����̸� ���ڿ��� �����ڵ���ؾ���. ������ ���ڿ��̶�� L�� �տ� �ٿ������ -> �����ڵ忡�� ��Ƽ�ڵ������� �Ұ����ϰ� �ٲٸ鼭 ���ڿ� �տ� L �� �ʿ� ������
	infile.Open(fileName,CFile::modeRead | CFile::typeBinary,&e);
	if(infile==NULL) {
		AfxMessageBox("NULL");						//���������� ������ ������ �˻�
		exit(1);
	}

	// BMP Header Information
	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hInfo;
	infile.Read(&hf,sizeof(BITMAPFILEHEADER));		//dibHf�� ��������� �о���δ�.
	infile.Read(&hInfo,sizeof(BITMAPINFOHEADER));	//���������� header�� �б�

	if(hf.bfType!=0x4D42) {
		AfxMessageBox("Not BMP file!!");			//bmp���� �˻�
		exit(1);
	}

	int ImgSize;
	if(hInfo.biBitCount!=24) {
		AfxMessageBox("Not 24bit");				//24bit���� �˻�
		exit(1);
	}else { 
		ImgSize = hInfo.biSizeImage;				//�̹��� ������
	}

	unsigned char *m_InImg;							//BGR �̹����� �� �迭
	m_InImg=new unsigned char [ImgSize];
	infile.Read(m_InImg, ImgSize);
	
	unsigned char *m_OutImg;							//RGB �̹����� �� �迭
	m_OutImg=new unsigned char [ImgSize];
	infile.Read(m_InImg, ImgSize);
	for(int i=0; i<ImgSize; i++) {
		m_OutImg[i]=m_InImg[ImgSize-i];
	}
	for(int i=0; i<ImgSize; i++) {
		m_InImg[i]=m_OutImg[i];
	}

	delete (m_OutImg);
	//infile.Close();

    glTexImage2D(GL_TEXTURE_2D, 0, 3, hInfo.biWidth, hInfo.biHeight, 0, GL_RGB,
        GL_UNSIGNED_BYTE, m_InImg);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,  GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);
}


BEGIN_MESSAGE_MAP(BmpToArray, CWnd)
END_MESSAGE_MAP()



// BmpToArray �޽��� ó�����Դϴ�.


