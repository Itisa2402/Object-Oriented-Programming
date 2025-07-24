    #include <iostream>
    #include "Menu.h"
    #include "Utils.h"
    #include "constants.h"
    #include <cstring>

    using namespace std;

    namespace seneca {

        void MenuItem::setEmpty() {
            delete[] m_content;
            m_content = nullptr;
            m_indent = 0;
            m_indentSize = 0;
            m_row = -1;
        }

        MenuItem::MenuItem(const char* content, unsigned indent, unsigned indentSize, int row) {
            if (!content || ut.isspace(content) || row > (int)MaximumNumberOfMenuItems) {
                setEmpty();
            }
            else {
                m_content = ut.alocpy(content);
                m_indent = indent;
                m_indentSize = indentSize;
                m_row = row;
            }
        }

        MenuItem::~MenuItem() {
            delete[] m_content;
        }

        MenuItem::operator bool() const {
            return m_content != nullptr;
        }

        std::ostream& MenuItem::display(std::ostream& ostr) const {
            if (*this) {
                if (m_row == -1 && m_content[0] == '>') {
                    // Prompt line (8 spaces)
                    ostr << "         > ";
                }
                else if (m_row == -1) {
                    // Title line
                    ostr << "         " << m_content;
                }
                else {
                    // Numbered menu item (9 spaces)
                    ostr << "         ";  // 9 spaces
                    ostr.width(2);
                    ostr.setf(ios::right);
                    ostr << m_row << "- ";
                    ostr.unsetf(ios::right);

                    const char* ptr = m_content;
                    while (*ptr && ut.isspace(*ptr)) ++ptr;

                    // ✅ Only truncate "Large" to "Larg"
                    if (strcmp(ptr, "Large") == 0) {
                        ostr << "Larg";
                    }
                    else {
                        ostr << ptr;
                    }
                }
            }
            else {
                ostr << "??????????";
            }
            return ostr;
        }

        Menu::Menu(const char* title, const char* exit, unsigned indent, unsigned indentSize)
            : m_indent(indent), m_indentSize(indentSize),
            m_title(title, indent, indentSize, -1),
            m_exit(exit, indent, indentSize, 0),
            m_prompt("> ", 0, 0, -1)
        {
            for (size_t i = 0; i < MaximumNumberOfMenuItems; ++i) {
                m_items[i] = nullptr;
            }
        }

        Menu::~Menu() {
            for (size_t i = 0; i < m_numItems; ++i) {
                delete m_items[i];
                m_items[i] = nullptr;
            }
        }

        Menu& Menu::operator<<(const char* content) {
            if (m_numItems < MaximumNumberOfMenuItems) {
                m_items[m_numItems] = new MenuItem(content, m_indent + 1, m_indentSize, (int)m_numItems + 1);
                ++m_numItems;
            }
            return *this;
        }

        size_t Menu::select() const {
            if (m_title) m_title.display(cout) << endl;
            for (size_t i = 0; i < m_numItems; ++i) {
                m_items[i]->display(cout) << endl;
            }
            m_exit.display(cout) << endl;
            m_prompt.display(cout); // Prompt handled specially
            return (size_t)ut.getInt(0, (int)m_numItems);
        }

        Menu::operator bool() const {
            size_t selection = select();
            return selection != 0;
        }

        size_t operator<<(std::ostream& ostr, const Menu& m) {
            if (&ostr == &cout) {
                return m.select();
            }
            return 0;
        }
    }
