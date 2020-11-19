#include "Gui/WorldSelect.h"
#include <GameUtilities/Event/EventManager.h>
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
#include <iostream>
#include "Settings.h"
#include "States/Id.h"
#include <GameUtilities/Event/ChangeState.h>
#include <GameUtilities/Event/PushState.h>
WorldSelect::WorldSelect()
{
    //ctor
	std::vector<std::string> worlds = {"World 1", "World 2", "World 3"};

	for(std::size_t i = 0; i < worlds.size(); i++)
	{
    		tgui::HorizontalLayout::Ptr layout1 = content->appendLayout();
		tgui::Button::Ptr button = tgui::Button::create(worlds[i]);
		layout1->add(button);
		
	}
	
		
	backButton = tgui::Button::create("Back");
    backButton->connect("pressed", [](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::PLAYER_INFO);
    });

    buttonLayout->add(backButton);

    defaultWorlds.push_back("World 1");
}

WorldSelect::~WorldSelect()
{
    //dtor
}
