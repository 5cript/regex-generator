HTTPS=0

if [ $HTTPS -eq 1 ]; then
    git clone https://github.com/NuiCpp/Nui.git
    git clone https://github.com/5cript/webview.git
else
    git clone git@github.com:NuiCpp/Nui.git
    git clone git@github.com:5cript/webview.git
fi