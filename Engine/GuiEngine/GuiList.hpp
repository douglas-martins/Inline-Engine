#pragma once
#include "GuiLayout.hpp"

namespace inl::gui {

class GuiList : public GuiLayout
{
public:
	GuiList(GuiEngine& guiEngine);
	GuiList(const GuiList& other):GuiLayout(other.guiEngine) { *this = other; }

	// Important to implement in derived classes
	virtual GuiList* Clone() const override { return new GuiList(*this); }

	using GuiLayout::AddItem;
	virtual void AddItem(Gui* gui) override { AddGui(gui); }
	virtual bool RemoveItem(Gui* gui) override { return RemoveGui(gui); }
	virtual std::vector<Gui*> GetItems() override { return GetChildren(); };

	void MakeVertical() { SetOrientation(eGuiOrientation::VERTICAL); }
	void MakeHorizontal() { SetOrientation(eGuiOrientation::HORIZONTAL); }

	void SetOrientation(eGuiOrientation dir);
	eGuiOrientation GetOrientation() { return orientation; }

protected:
	virtual Vec2 ArrangeChildren() override;

protected:
	eGuiOrientation orientation;
};

} // namespace inl::gui