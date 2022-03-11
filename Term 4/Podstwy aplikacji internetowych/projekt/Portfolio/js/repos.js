function viewRepos() {
  fetch("https://api.github.com/users/jakubLabendowicz/repos")
    .then(res => res.json())
    .then(res => {
      for (var i = 0; i < res.length; i++) {
        console.log(res[i].name + "\n" + res[i].html_url + "\n" + "https://labendowicz.pl/" + res[i].name);
        const $repositoriesContainer = $("#repositoriesContainer");
        const $project = $("<div class='project flex-column-container'><div class='project-logo' style='height: 20px'></div><div class='project-container'><div class='project-header'>"
          + res[i].name
          + "</div><div class='flex-column-container' style='gap: 0px'><a href='"
          + "https://labendowicz.pl/"
          + res[i].name
          + "' class='card-text'>Demo</a><a href='"
          + res[i].html_url
          + "' class='card-text'>Repozytorium</a></div></div></div>");
        $repositoriesContainer.append($project);
      }
    })
}

viewRepos();
