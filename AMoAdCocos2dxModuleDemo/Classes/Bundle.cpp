#include "Bundle.h"

USING_NS_CC;

Bundle* Bundle::instance = NULL;

Bundle::Bundle()
{
}
Bundle* Bundle::getInstance()
{
    if (NULL == instance)
    {
        instance = new Bundle();
    }
    return instance;
}

