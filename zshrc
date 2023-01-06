# Jobs: Fish-like suggestion for command history
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh 
source /usr/share/oh-my-zsh/plugins/sudo/sudo.plugin.zsh
#source /usr/share/zsh-autocomplete/zsh-autocomplete.plugin.zsh
# Select all suggestion instead of top on result only
zstyle ':autocomplete:tab:*' insert-unambiguous yes
zstyle ':autocomplete:tab:*' widget-style menu-select
zstyle ':autocomplete:*' min-input 2
#bindkey $key[Up] up-line-or-history
#bindkey $key[Down] down-line-or-history

##################################################
# Fish like syntax highlighting
# Requires "zsh-syntax-highlighting" from apt

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 

# Vi mode
#bindkey -v
#export KEYTIMEOUT=1

bindkey "^[[H" beginning-of-line
bindkey "^[[F" end-of-line
bindkey "^[[3~" delete-char
# Salto de palabra hacia la derecha
bindkey "^[[1;2C" forward-word
# Salto de palabra hacia la izquierda
bindkey "^[[1;2D" backward-word



