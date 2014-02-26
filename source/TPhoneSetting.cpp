#include "TPhoneSetting.h"
#include "Adapter.h"
#include "ControlHeaders.h"
#include "CommandDefinition.h"


TPhoneSetting::TPhoneSetting(TPhoneSetting *parent) :
	QWidget(parent),
	UiResource(new Ui::PhoneSetting)
{
    UiResource->setupUi(this);

    int maxx = UiResource->PositionX->maximum();
    UiResource->PositionX->setValue((int)(maxx / 2));
    int maxy = UiResource->PositionY->maximum();
    UiResource->PositionY->setValue((int)(maxy / 2));

    QObject::connect(UiResource->ScaleSlider, SIGNAL(valueChanged(int)), this, SLOT(PhoneScreenScaleChange(int)));
    QObject::connect(UiResource->OK, SIGNAL(clicked()), this, SLOT(PhoneScreenSizeChange()));
    QObject::connect(UiResource->PositionX, SIGNAL(valueChanged(int)), this, SLOT(PhoneScreenPositionXChange(int)));
    QObject::connect(UiResource->PositionY, SIGNAL(valueChanged(int)), this, SLOT(PhoneScreenPositionYChange(int)));
}

TPhoneSetting::~TPhoneSetting(){
    delete UiResource;
}

void TPhoneSetting::PhoneScreenScaleChange(int value){
    std::ostringstream stringbuffer;
    float scale = (float)value/10000.0f;
    stringbuffer<<SYS_PHONESCREENSCALE<<" "<<scale;
    AdapterPushEditorMessage(0,stringbuffer.str());
}

void TPhoneSetting::PhoneScreenSizeChange(){
    QString width = UiResource->Width->text();
    QString height = UiResource->Height->text();
    if(width.size()>0 && height.size() >0){
	std::ostringstream stringbuffer;
	stringbuffer << SYS_PHONESCREENSIZE << " " << width.toInt() << " " << height.toInt();
	AdapterPushEditorMessage(0,stringbuffer.str());
    }
}

void TPhoneSetting::PhoneScreenPositionXChange(int value)
{
    std::ostringstream stringbuffer;
    stringbuffer<<SYS_PHONESCREENPOSITIONX<<" "<<value-2500;
    AdapterPushEditorMessage(0,stringbuffer.str());
}

void TPhoneSetting::PhoneScreenPositionYChange(int value)
{
    std::ostringstream stringbuffer;
    stringbuffer<<SYS_PHONESCREENPOSITIONY<<" "<<value-2500;
    AdapterPushEditorMessage(0,stringbuffer.str());
}
