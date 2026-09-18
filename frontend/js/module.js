var Module = {
    onRuntimeInitialized: () => {
        Module.main();
    }
};

window.setupSkinPanelOutsideClick = function () {
    document.addEventListener("click", function (event) {
        const panel = document.getElementById("skin-panel");
        const button = document.getElementById("skin-button");

        if (!panel || !button)
            return;

        if (!panel.contains(event.target) &&
            !button.contains(event.target))
        {
            panel.classList.remove("skin-panel-visible");
        }
    });
};