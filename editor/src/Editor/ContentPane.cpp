#include "Editor/ContentPane.h"


/****************************************************************************//**
*   @brief Constructor.
********************************************************************************/
ContentPane::ContentPane()
{
    //ctor
    this->setSize(380, 300);
    layoutSize.x = this->getSize().x - this->getScrollbarWidth();
    layoutSize.y = this->getSize().y * 0.1f;
    getRenderer()->setBackgroundColor(sf::Color::Transparent);
}


/****************************************************************************//**
*   @brief Create a space in the panel.
********************************************************************************/
tgui::HorizontalLayout::Ptr ContentPane::appendLayout()
{
    tgui::HorizontalLayout::Ptr layout = tgui::HorizontalLayout::create();
    layout->setSize(layoutSize);

    if(!layouts.empty())
    {
        sf::Vector2f pos = layouts.back()->getPosition();
        pos.y = pos.y + layoutSize.y;
        layout->setPosition(pos);
    }
    //mainLayout->add(layout);

    layouts.push_back(layout);
    this->add(layout);
    return layout;
}


/****************************************************************************//**
*   @brief  Create a single line with some text.
*   @param  text to be displayed.
********************************************************************************/
void ContentPane::appendSpacer()
{
    appendLayout();
}


/****************************************************************************//**
*   @brief Create a layout and insert it into the panel. Widgets can then be
*           added to the layout maually.
*   @return A pointer to the layout.
********************************************************************************/
void ContentPane::appendSection(const sf::String &text)
{
    tgui::HorizontalLayout::Ptr layout = appendLayout();
    tgui::Label::Ptr temp = tgui::Label::create(text);
    layout->add(temp);
}


/****************************************************************************//**
*   @brief  Create an edit box and insert it at the end of the panel.
*   @param  Description of the property.
*   @param  Text that will be displayed in the editbox.
*   @return A pointer to the editbox
********************************************************************************/
tgui::EditBox::Ptr ContentPane::appendEditBox(const sf::String &label, const sf::String &text)
{
    tgui::Label::Ptr boxLabel = tgui::Label::create(label);
    tgui::EditBox::Ptr editBox = tgui::EditBox::create();
    editBox->setText(text);
    tgui::HorizontalLayout::Ptr layout = appendLayout();
    tgui::Panel::Ptr panel = tgui::Panel::create();
    panel->getRenderer()->setBackgroundColor(sf::Color::Transparent);
    layout->add(boxLabel);
    layout->add(panel);
    panel->add(editBox);

    return editBox;
}


/****************************************************************************//**
*   @brief  Create a checkbox and insert it at the end of the panel.
*   @param  Description of the property.
*   @param  True if the checkbox should be displayed as checked and false otherwise
*   @return A pointer to the checkbox.
********************************************************************************/
tgui::CheckBox::Ptr ContentPane::appendCheckBox(const sf::String &label, const bool val)
{
    tgui::Label::Ptr checkboxLabel = tgui::Label::create(label);
    tgui::CheckBox::Ptr checkBox = tgui::CheckBox::create();
    tgui::HorizontalLayout::Ptr layout = appendLayout();
    layout->add(checkboxLabel);
    tgui::Panel::Ptr panel = tgui::Panel::create();
    panel->getRenderer()->setBackgroundColor(sf::Color::Transparent);
    panel->add(checkBox);
    layout->add(panel);
    checkBox->setChecked(val);

    return checkBox;
}


/****************************************************************************//**
*   @brief  Create a combobox and insert it at the end of the panel.
*   @param  Description of the property.
*   @param  A vector of strings that wil be listed as choices in the combobox
*   @return A pointer to the combobox.
********************************************************************************/
tgui::ComboBox::Ptr ContentPane::appendComboBox(const sf::String &label, std::vector<sf::String> &elements)
{
    tgui::Label::Ptr comboLabel = tgui::Label::create(label);
    tgui::ComboBox::Ptr box = tgui::ComboBox::create();

    for(std::size_t i = 0; i < elements.size(); ++i)
    {
        box->addItem(elements[i], elements[i]);
    }

    tgui::HorizontalLayout::Ptr layout = appendLayout();
    tgui::Panel::Ptr panel = tgui::Panel::create();
    panel->getRenderer()->setBackgroundColor(sf::Color::Transparent);
    layout->add(comboLabel);
    layout->add(panel);
    panel->add(box);
    return box;
}


/****************************************************************************//**
*   @brief  Create a slider and insert it at the end of the panel.
*   @param  Description of the property.
*   @return Pointer to the created slider.
********************************************************************************/
tgui::Slider::Ptr ContentPane::appendSlider(const sf::String &label)
{
    tgui::Label::Ptr sliderLabel = tgui::Label::create(label);
    tgui::Slider::Ptr slider = tgui::Slider::create();
    tgui::HorizontalLayout::Ptr layout = appendLayout();
    layout->add(sliderLabel);
    layout->add(slider);

    return slider;
}


tgui::Button::Ptr ContentPane::appendButton(const sf::String &label, const int &id)
{
    tgui::Label::Ptr buttonLabel = tgui::Label::create(label);
    tgui::Button::Ptr button = tgui::Button::create(label);
    tgui::HorizontalLayout::Ptr layout = appendLayout();
    layout->add(buttonLabel);
    layout->add(button);
}


/****************************************************************************//**
*   @brief  Get a pointer to any layout in the panel.
*   @param  The index of the layout.
*   @return A pointer to the layout.
********************************************************************************/
tgui::HorizontalLayout::Ptr ContentPane::get(const std::size_t &i)
{
    return layouts.at(i);
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
ContentPane::~ContentPane()
{
    //dtor
}
