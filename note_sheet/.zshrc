export PATH="/usr/local/bin:$PATH"

USER=LEECHI
export USER
MAIL=LeeChi@student.your42network
export MAIL

alias francinette=/Users/ichr/francinette/tester.sh

alias paco=/Users/ichr/francinette/tester.sh

export LIBRARY_PATH=/opt/homebrew/lib

parse_git_branch() {
    git branch 2> /dev/null | sed -n -e 's/^\* \(.*\)/[\1]/p'
}
COLOR_DEF='%f'
COLOR_USR='%F{243}'
COLOR_DIR='%F{46}'
COLOR_GIT='%F{39}'
# About the prefixed `$`: https://tldp.org/LDP/Bash-Beginners-Guide/html/sect_03_03.html#:~:text=Words%20in%20the%20form%20%22%24',by%20the%20ANSI%2DC%20standard.
# NEWLINE=$'\n'
NEWLINE=$'\n''👉'

# Set zsh option for prompt substitution
setopt PROMPT_SUBST
export PROMPT='${COLOR_USR}%n@%M ${COLOR_DIR}%d ${COLOR_GIT}$(parse_git_branch)${COLOR_DEF}${NEWLINE}'

gP() {
    git checkout main
    # Fetch and prune remote-tracking branches
    git fetch -p

    # Find branches that are marked as [gone]
    branches=$(git for-each-ref --format '%(refname:short) %(upstream:track)' refs/heads/ | grep '\[gone\]' | awk '{print $1}')

    # Check if any branches are marked as [gone]
    if [ -z "$branches" ]; then
        echo "No branches to delete."
    else
        for branch in $branches; do
            git branch -D "$branch"
            echo "Deleted branch '$branch'"
        done
    fi
    git pull
}

export PATH="$PATH:/Users/ichr/development/flutter/bin"

