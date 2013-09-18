#pragma once

#include <QDesignerCustomWidgetInterface>

class PlainColorPickerPlugin : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)
	Q_PLUGIN_METADATA(IID "plaincolorpicker" FILE "plaincolorpicker.json")

public:
	PlainColorPickerPlugin(QObject *parent = nullptr);

	bool isContainer() const override;
	bool isInitialized() const override;
	QIcon icon() const override;
	QString domXml() const override;
	QString group() const override;
	QString includeFile() const override;
	QString name() const override;
	QString toolTip() const override;
	QString whatsThis() const override;
	QWidget *createWidget(QWidget *parent) override;
	void initialize(QDesignerFormEditorInterface *formEditor) override;

 private:
	bool initialized;
 };