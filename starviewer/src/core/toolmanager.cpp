/***************************************************************************
 *   Copyright (C) 2005-2006 by Grup de Gr�fics de Girona                  *
 *   http://iiia.udg.es/GGG/index.html?langu=uk                            *
 *                                                                         *
 *   Universitat de Girona                                                 *
 ***************************************************************************/
#include "toolmanager.h"
#include "qviewer.h"
#include "tool.h"

namespace udg {

ToolManager::ToolManager(QObject *parent)
 : QObject(parent)
{
}

ToolManager::~ToolManager()
{
}

bool ToolManager::setCurrentTool( QString toolName )
{
    if( m_toolList.find( toolName ) != m_toolList.end() )
    {
        m_currentToolName = toolName;
        return true;
    }
    else
        return false;
}

Tool *ToolManager::getTool( QString toolName )
{
    if( m_toolList.find( toolName ) != m_toolList.end() )
        return m_toolList[toolName];
    else
        return 0;
}

void ToolManager::forwardEvent( unsigned long eventID )
{
    if( m_toolList.find( m_currentToolName ) != m_toolList.end() )
    {
        m_toolList[m_currentToolName]->handleEvent( eventID );
    }
}

}
