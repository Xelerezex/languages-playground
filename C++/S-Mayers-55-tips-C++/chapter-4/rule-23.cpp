// Rule #22
// Chose functions, that not member data, nor friends.

class WebBrowser
{
    public:
        void clearCashe() {}
        void clearHistory() {}
        void removeCookies() {}
};

void clearBrowser(WebBrowser &wb)
{
    wb.clearCashe();
    wb.clearHistory();
    wb.removeCookies();
}

int main()
{
    WebBrowser wb;
    clearBrowser(wb);
}
