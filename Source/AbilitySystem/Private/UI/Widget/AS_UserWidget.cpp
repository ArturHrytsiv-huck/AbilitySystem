// Copyright Artur Hrytsiv


#include "UI/Widget/AS_UserWidget.h"

void UAS_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	
	WidgetControllerSet();
}
