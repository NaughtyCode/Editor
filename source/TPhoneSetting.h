#ifndef WrapPhoneSetting_H
#define WrapPhoneSetting_H


#include "ControlHeaders.h"
#include "uiphonesetting.h"

class TPhoneSetting : public QWidget
{
    Q_OBJECT
    
public:
    explicit TPhoneSetting(TPhoneSetting *parent = 0);
    ~TPhoneSetting();
    
public slots:
    void PhoneScreenScaleChange(int value);
    void PhoneScreenSizeChange();
    void PhoneScreenPositionXChange(int value);
    void PhoneScreenPositionYChange(int value);
    
private:
    Ui::PhoneSetting* UiResource;
};

#endif
