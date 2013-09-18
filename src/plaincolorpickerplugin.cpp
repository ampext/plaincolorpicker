#include "plaincolorpickerplugin.h"
#include "plaincolorpicker.h"

#include <QtPlugin>

PlainColorPickerPlugin::PlainColorPickerPlugin(QObject *parent) : QObject(parent)
{
    initialized = false;
}

void PlainColorPickerPlugin::initialize(QDesignerFormEditorInterface *formEditor)
{
	if(initialized) return;
	initialized = true;
}

bool PlainColorPickerPlugin::isInitialized() const
{
	return initialized;
}

QWidget *PlainColorPickerPlugin::createWidget(QWidget *parent)
{
	return new PlainColorPicker(parent);
}

QString PlainColorPickerPlugin::name() const
{
	return "PlainColorPicker";
}

QString PlainColorPickerPlugin::group() const
{
	return "Input Widgets";
}

QIcon PlainColorPickerPlugin::icon() const
{
	return QIcon(":/icon.png");
}

QString PlainColorPickerPlugin::toolTip() const
{
	return "";
}

QString PlainColorPickerPlugin::whatsThis() const
{
	return "";
}

bool PlainColorPickerPlugin::isContainer() const
{
	return false;
}

QString PlainColorPickerPlugin::domXml() const
{
	return "<ui language=\"c++\">\n"
			" <widget class=\"PlainColorPicker\" name=\"plainColorPicker\">\n"
			"  <property name=\"geometry\">\n"
			"   <rect>\n"
			"    <x>0</x>\n"
			"    <y>0</y>\n"
			"    <width>150</width>\n"
			"    <height>16</height>\n"
			"   </rect>\n"
			"  </property>\n"
			"  <property name=\"toolTip\" >\n"
			"   <string>Color</string>\n"
			"  </property>\n"
			"  <property name=\"whatsThis\" >\n"
			"   <string>Color picker widget</string>\n"
			"  </property>\n"
			" </widget>\n"
			"</ui>\n";
}

QString PlainColorPickerPlugin::includeFile() const
{
	return "plaincolorpicker.h";
}