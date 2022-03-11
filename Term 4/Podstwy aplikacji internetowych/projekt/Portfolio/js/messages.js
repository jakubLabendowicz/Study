function viewMessages() {
  var storage = new Storage("form");

  if (storage.downloadLocal() == null) {

  } else {
    var stringForms = storage.downloadLocal();
    var forms = JSON.parse(stringForms);


    for (var i = forms.length-1; i >= 0; i--) {
      if (forms[i] != null) {
        console.log(forms[i]);

        var read;
        if (forms[i].read == false || forms[i].read == null) {
          var read = "Oznacz jako przeczytane";
        } else {
          var read = "Oznacz jako nieprzeczytane";
        }


        const $messagesContainer = $("#messagesContainer");
        const $form = $(`<div class="width-45 card-box" style="text-align: left;">
          <div class="card-box-container contact-box-container">
            <div>
              <div class="card-header">${forms[i].name}</div>
              <div class="card-description">${forms[i].email}</div>
              <div class="card-description">${forms[i].phone}</div>
            </div>
            <div class="card-text">${forms[i].message}</div>
            <div class="message-buttons">
              <div class="card-button" id="message-button" onclick="delateMessage(${i})">
                <div class="card-button-container" id="message-button-container">Usuń wiadomość</div>
              </div>
              <div class="card-button" id="message-button" onclick="readMessage(${i})">
                <div class="card-button-container" id="message-button-container">${read}</div>
              </div>
            </div>
          </div>
        </div>
      `);


        $messagesContainer.append($form);
      }
    }
  }
}

function delateMessage(id) {
  var storage = new Storage("form");

  var stringForms = storage.downloadLocal();
  var forms = JSON.parse(stringForms);

  delete forms[id];

  storage.uploadLocal(JSON.stringify(forms));

  window.open('mailbox.html', '_self')
}

function readMessage(id) {
  var storage = new Storage("form");

  var stringForms = storage.downloadLocal();
  var forms = JSON.parse(stringForms);

  if (forms[id].read == false || forms[id].read == null) {
    forms[id].read = true;
  } else {
    forms[id].read = false;
  }

  storage.uploadLocal(JSON.stringify(forms));

  window.open('mailbox.html', '_self')
}
