#ifndef PROPERTIESPANEL_H
#define PROPERTIESPANEL_H
#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
class PropertiesPanel: public tgui::ScrollablePanel
{
    public:
        PropertiesPanel(const int width, const int height);
                /****************************************************************************//**
        *   @brief Create a space in the panel.
        ********************************************************************************/
        void appendSpacer();


        /****************************************************************************//**
        *   @brief  Create a single line with some text.
        *   @param  text to be displayed.
        ********************************************************************************/
        tgui::Label::Ptr appendSection(const sf::String &text);


        /****************************************************************************//**
        *   @brief Create a layout and insert it into the panel. Widgets can then be
        *           added to the layout maually.
        *   @return A pointer to the layout.
        ********************************************************************************/
        tgui::HorizontalLayout::Ptr appendLayout();


        /****************************************************************************//**
        *   @brief  Create an edit box and insert it at the end of the panel.
        *   @param  Description of the property.
        *   @param  Text that will be displayed in the editbox.
        *   @return A pointer to the editbox
        ********************************************************************************/
        tgui::EditBox::Ptr appendEditBox(const sf::String &label, const sf::String &text);


        /****************************************************************************//**
        *   @brief  Create a checkbox and insert it at the end of the panel.
        *   @param  Description of the property.
        *   @param  True if the checkbox should be displayed as checked and false otherwise
        *   @return A pointer to the checkbox.
        ********************************************************************************/
        tgui::CheckBox::Ptr appendCheckBox(const sf::String &label, const bool val = false);


        /****************************************************************************//**
        *   @brief  Create a combobox and insert it at the end of the panel.
        *   @param  Description of the property.
        *   @param  A vector of strings that wil be listed as choices in the combobox
        *   @return A pointer to the combobox.
        ********************************************************************************/
        tgui::ComboBox::Ptr appendComboBox(const sf::String &label, std::vector<sf::String> &elements);

        /****************************************************************************//**
        *   @brief  Create a slider and insert it at the end of the panel.
        *   @param  Description of the property.
        *   @return Pointer to the created slider.
        ********************************************************************************/
        tgui::Slider::Ptr appendSlider(const sf::String &label);


        tgui::Button::Ptr appendButton(const sf::String &label, const int &id);

        /****************************************************************************//**
        *   @brief  Get a pointer to any layout in the panel.
        *   @param  The index of the layout.
        *   @return A pointer to the layout.
        ********************************************************************************/
        tgui::HorizontalLayout::Ptr get(const std::size_t &i);
        virtual ~PropertiesPanel();

    protected:

    private:
        std::vector<tgui::HorizontalLayout::Ptr> layouts;
        sf::Vector2f layoutSize;
};

#endif // PROPERTIESPANEL_H
