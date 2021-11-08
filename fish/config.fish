if status is-interactive
    # Commands to run in interactive sessions can go here
end

set fish_greeting
xset r rate 350 50 &
alias yeet='yay -Rcs'
alias ls='ls -lah --color=auto'
alias i3='vim ~/.config/i3/config'
alias i3status='vim ~/.config/i3/i3status.conf'
alias dwm='cd ~/.config/dwm && vim config.h'
alias slstatus='cd ~/.config/slstatus && vim config.h'
alias stconf='cd ~/.config/st && vim config.h'
alias fishconf='vim ~/.config/fish/config.fish'
alias kittyconf='vim ~/.config/kitty/kitty.conf'
alias bspwm='vim ~/.config/bspwm/bspwmrc'
alias sxhkd='vim ~/.config/sxhkd/sxhkdrc'
alias sleep='systemctl suspend && betterlockscreen -l'
alias kwl='dbus-launch --sh-syntax --exit-with-session startplasma-wayland'
alias dbus='dbus-launch --sh-syntax --exit-with-session'
#alias reboot='doas openrc-shutdown -r now'
#alias off='doas openrc-shutdown -p now'
alias gwl='XDG_SESSION_TYPE=wayland dbus-run-session gnome-session'

set_color c197ac
