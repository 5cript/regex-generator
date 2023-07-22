HTTPS=0

if [ $HTTPS -eq 1 ]; then
    git clone https://github.com/NuiCpp/Nui.git
else
    git clone git@github.com:NuiCpp/Nui.git
fi