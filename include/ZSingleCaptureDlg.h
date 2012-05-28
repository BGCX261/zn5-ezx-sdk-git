/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     changed return type for functions:
#                            ZSingleCaptureDlg::getLineEdit()
*/

#ifndef _ZSINGLECAPTUREDLG_H
#define _ZSINGLECAPTUREDLG_H

#include <ZPopup.h>
//
#include <ZLineEdit.h>
#include <ZMultiLineEdit.h>

/* Size:216=54*4 */

class ZSingleCaptureDlg : public ZPopup
{
	Q_OBJECT
	void *point;
public: 
	enum CaptureDlgType
	{
		normal, secret, normal2, secret2 
	};
	ZSingleCaptureDlg(QString const&, QString const&, ZSingleCaptureDlg::CaptureDlgType, QWidget*, char const*, bool, unsigned int, int);
	ZSingleCaptureDlg(QWidget*, char const*, bool, unsigned int);
	virtual ~ZSingleCaptureDlg();
	CaptureDlgType getDialogType();
  	ZWidget* getEditWidget();
  	ZLineEdit* getLineEdit();
  	ZMultiLineEdit* getMultiLineEdit();
  	QString getResultText();
  	bool setEditWidget(ZWidget*);
private:
	void initialize(ZSingleCaptureDlg::CaptureDlgType);
public slots:
	virtual void  slotLSKClicked();
	virtual void  slotRSKClicked();
	virtual void  slotResizeAllChild(int);
};

#endif
