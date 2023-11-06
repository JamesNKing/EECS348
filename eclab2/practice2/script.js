function updateStyles() {
    const rgbValue = document.getElementById('rgb-input').value;
    const borderWidth = document.getElementById('border-width-input').value;
    
    const sampleText = document.getElementById('sample-text');

    // applies RGB color to the paragraph text and border
    sampleText.style.color = `rgb(${rgbValue})`;
    sampleText.style.borderColor = `rgb(${rgbValue})`;

    // applies border width
    sampleText.style.borderWidth = `${borderWidth}px`;
}

